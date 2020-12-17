#ifndef SMTPCLIENT_H
#define SMTPCLIENT_H

#include <QObject>
#include <QTimer>
#include <QtNetwork/QSslSocket>
#include <QtNetwork/QAbstractSocket>

#include "email.h"

namespace Status {
    enum e{
        Success,
        Failed
    };
}

/**
 * @brief The SMTPClient class est la definition du client smtp
 */
class Smtpclient : public QObject
{
    Q_OBJECT

public:
    // smtp communique sur le port 25 ou 465 pour une communication en ssl.
    Smtpclient();
    Smtpclient(QString host,
               int port = 465,
               int conTimeout = 30000,
               int timeout = 60000);
    ~Smtpclient();

    void envoiEmail(Email email);

signals:
    void status(Status::e status,QString errorMessage = "");
private slots:
    void comunication();
    void stopCom();

private:
    enum etats{
        Tls,
        HandShake,
        Auth,
        User,
        Pass,
        Rcpt,
        Mail,
        Data,
        Init,
        Body,
        Quit,
        Close
    };
    QString Host;
    int Port;
    int ConTimeout;
    int Timeout;
    Email mail;
    QSslSocket *socket;
    QTextStream *textstream;
    int etat;
    QString reponse;
};

#endif // SMTPCLIENT_H
