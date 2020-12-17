#include "smtpclient.h"

Smtpclient::Smtpclient()
{

}

Smtpclient::Smtpclient(QString host, int port, int conTimeout, int timeout)
{
    this->Host = host;
    this->Port = port;
    this->ConTimeout = conTimeout;
    this->Timeout = timeout;

    this->textstream = NULL;
    this->socket = new QSslSocket(this);
    connect(this->socket, SIGNAL(readyRead()), this, SLOT(comunication()));
    qDebug()<<"les valeurs init sont: "<<Host<<" "<<Port<<" "<<ConTimeout<<" "<<Timeout;
}

Smtpclient::~Smtpclient()
{
    delete this->textstream;
    this->socket->abort();
    this->socket->deleteLater();
}

void Smtpclient::envoiEmail(Email email)
{
    this->mail = email;
    QString newcontent = "";
    newcontent.append("To: " + this->mail.getTo().get_addresse() + "\n");
    newcontent.append("From: " + this->mail.getFrom().get_addresse() + "\n");
    newcontent.append("Subject: " + this->mail.getSubject() + "\n\n");
    newcontent.append(this->mail.getContenu());

    newcontent.replace(QString::fromLatin1("\n"), QString::fromLatin1("\r\n"));
    newcontent.replace(QString::fromLatin1("\r\n.\r\n"), QString::fromLatin1("\r\n..\r\n"));
    this->mail.setContenu(newcontent);
    this->etat = Init;
    // connection a l'hote

    this->socket->connectToHostEncrypted(this->Host, this->Port);

   if(!this->socket->waitForConnected(ConTimeout)){
       emit status(Status::Failed, this->socket->errorString());
       qDebug()<<"je ne suis pas passé";
       return;
   }
    qDebug()<<"je suis passé";
   this->textstream = new QTextStream(this->socket);

   QTimer::singleShot(this->Timeout, this, SLOT(stopCom()));


}

void Smtpclient::comunication()
{
    QString respo;
    do{
        respo = this->socket->readLine();
        this->reponse += respo;
    }while(this->socket->canReadLine() && respo[3] != ' ');

    respo.truncate(3);
    qDebug()<<"respo en entrer"<<respo;
    if(this->etat == Init && respo == "220"){
        *this->textstream << "EHLO localhost" <<"\r\n";
        this->textstream->flush();

        this->etat = HandShake;
        qDebug()<<"etat 1 response:"<<respo;
    }
    else if(this->etat == HandShake && respo == "250"){
        this->socket->startClientEncryption();
        this->socket->waitForEncrypted(this->ConTimeout);

        *this->textstream << "EHLO localhost" <<"\r\n";
        this->textstream->flush();

        this->etat = Auth;
        qDebug()<<"etat 2 response:"<<respo;

    }
    else if(this->etat == Auth && respo == "250"){
        *this->textstream << "AUTH LOGIN" <<"\r\n";
        this->textstream->flush();

        this->etat = User;
        qDebug()<<"etat 3 response:"<<respo;
    }
    else if(this->etat == User && respo == "334"){
        QString a= this->mail.getComptegoogle().get_addresse();
        *this->textstream <<QByteArray().append(this->mail.getComptegoogle().get_addresse()).toBase64() <<"\r\n";
        this->textstream->flush();

        this->etat = Pass;
        qDebug()<<"etat 4 response:"<<respo;
    }
    else if(this->etat == Pass && respo == "334"){
        QString a =this->mail.getComptegoogle().get_passwd();
        *this->textstream <<QByteArray().append(this->mail.getComptegoogle().get_passwd()).toBase64() <<"\r\n";
        this->textstream->flush();

        this->etat = Mail;
        qDebug()<<"etat 5 response:"<<respo;
    }
    else if(this->etat == Mail && respo == "235"){
        *this->textstream << "Mail From: <" << this->mail.getFrom().get_addresse() << ">\r\n";
        this->textstream->flush();

        this->etat = Rcpt;
        qDebug()<<"etat 6 response:"<<respo;
    }
    else if(this->etat == Rcpt && respo == "250"){
        *this->textstream << "RCPT TO: <" << this->mail.getTo().get_addresse() << ">\r\n";
        this->textstream->flush();

        this->etat = Data;
        qDebug()<<"etat 7 response:"<<respo;
        qDebug()<<this->mail.getTo().get_addresse() ;
    }
    else if(this->etat == Data && respo == "250"){
        *this->textstream << "DATA\r\n";
        this->textstream->flush();

        this->etat = Body;
         qDebug()<<"etat 8 response:"<<respo;
    }
    else if(this->etat == Body && respo == "354"){
        *this->textstream << this->mail.getContenu() <<"\r\n.\r\n";
        this->textstream->flush();

        this->etat = Quit;
        qDebug()<<"etat 9 response:"<<respo;
    }
    else if(this->etat == Quit && respo == "250"){
        *this->textstream << "QUIT\r\n";
        this->textstream->flush();

        this->etat = Close;
        emit status(Status::Success);
    }
    else if(this->etat == Close){
        return;
    }
    else{
        this->etat = Close;
        emit status(Status::Failed, this->reponse);
    }
}

void Smtpclient::stopCom()
{
    if(this->socket->isOpen()){
        this->socket->abort();
        this->etat = Close;
        emit status(Status::Failed, "Arret du processus car Timeut atteint ");

    }
}


