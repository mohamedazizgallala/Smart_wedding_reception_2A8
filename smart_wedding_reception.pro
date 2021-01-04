QT += core gui sql
QT += network
QT += printsupport
QT += charts
QT +=multimedia
QT +=serialport
QT += widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG +=console

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    animateur.cpp \
    arduino.cpp \
    car.cpp \
    coiffeurs.cpp \
    connexion.cpp \
    decorateur.cpp \
    evenement.cpp \
    exportexcelobject.cpp \
    graphiste.cpp \
    local.cpp \
    locateurs.cpp \
    main.cpp \
    mainwindow.cpp \
    offre.cpp \
    photographe.cpp \
    pie_location.cpp \
    send_email_location.cpp \
    smtp_location.cpp \
    statbeaute.cpp \
    traiteur.cpp

HEADERS += \
    animateur.h \
    arduino.h \
    car.h \
    coiffeurs.h \
    connexion.h \
    decorateur.h \
    evenement.h \
    exportexcelobject.h \
    graphiste.h \
    local.h \
    locateurs.h \
    mainwindow.h \
    offre.h \
    photographe.h \
    pie_location.h \
    send_email_location.h \
    smtp_location.h \
    statbeaute.h \
    traiteur.h

FORMS += \
    mainwindow.ui \
    pie_location.ui \
    send_email_location.ui \
    statbeaute.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    img.qrc \
    sound.qrc \
    buttonsound.qrc \
    images.qrc

DISTFILES += \
    ../graph/info.txt \
    ../graph/wess.pro.user \
    The Voice_ button sound effect.wav \
    image/103854343_259019528641376_3453490155072435271_n.jpg \
    image/121527165_283003159406450_6476818707641022998_n.jpg \
    image/126205197_181879636821640_5647087082797402769_n.png \
    image/XkgL1v.jpg \
    image/ajout.png \
    image/bfa_power-off_flat-circle-white-on-ios-pink-gradient_512x512.png \
    image/computer-icons-button-arrow-png-favpng-1sXz4GPFdZq5tvjfd9Q8gYCVt.png \
    image/eng.png \
    image/france.png \
    image/images (1).jfif \
    image/images.jfif \
    image/login-user.png \
    image/login.png \
    image/logout-icon-5-256.png \
    image/modify.png \
    image/pdf.png \
    image/refresh.png \
    image/search icon.png \
    image/thebigdaylogo.png \
    image/trash.png \
    image/tri.jfif \
    image/téléchargement (1).jfif \
    image/téléchargement.jfif \
    image/vanguardslogo.png \
    image/wedd.jpg

SUBDIRS += \
    ../graph/wess.pro
