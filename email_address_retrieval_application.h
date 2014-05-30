#ifndef CONTROL_H
#define CONTROL_H

#include <QObject>
#include <QMap>
#include <QString>
#include <iostream>
#include <QApplication>
#include <QTextCodec>

#include <vmime/vmime.hpp>
#include <vmime/net/session.hpp>
#include <vmime/net/store.hpp>
#include <vmime/utility/url.hpp>
#include <vmime/net/messageSet.hpp>

#include "memory.h"
#include "main_window.h"
#include "mail_server.h"
#include "mail_box.h"


class EmailAddressRetrievalApplication: public QObject
{
    Q_OBJECT

public:
   EmailAddressRetrievalApplication();

    int exec(int argc, char *argv[]);
    QMap <QString,QString> showUserProfile();    


private:
    QMap <QString,QString> authorizationData;
    MainWindow* mainWindow;
    MailBox* mb;


signals:
    void changeForm(QList<QString> &headers);

public slots:
    void onLogin(QMap<QString, QString> user);
    void setCentralOnDesktop();
};

#endif // CONTROL_H
