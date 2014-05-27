#ifndef CONTROL_H
#define CONTROL_H

#include <QObject>
#include <QMap>
#include <QString>
#include <functional>
#include <iostream>
#include <fstream>
//#include <string>
#include <QApplication>

#include <vmime/vmime.hpp>
#include <vmime/net/session.hpp>
#include <vmime/net/store.hpp>
#include <vmime/utility/url.hpp>
#include <vmime/net/messageSet.hpp>

#include "memory.h"
#include "Time_Out_Handler.h"
#include "Tracer.h"
#include "Show_Messages.h"
#include "Main_Window.h"

class EmailAddressRetrievalApplication: public QObject
{
    Q_OBJECT

struct strMessages
{
    QList <int>  num;
    QList <QString> msgPart;
};

public:
   EmailAddressRetrievalApplication();

    int exec(int argc, char *argv[]);
    QMap <QString,QString> showUserProfile();    
    strMessages fetchNewMessages(vmime::shared_ptr  <vmime::net::store>&st);
    strMessages fetchReadMessages(vmime::shared_ptr  <vmime::net::store>&st);
    strMessages getNewMasseges();
    strMessages getReadMasseges();
    void deleteMsg(int &index);
    vmime::string getImap();
    bool imapConnection();
    void extractMsg();
    vmime::shared_ptr <vmime::net::folder> folder;

private:
    QMap <QString,QString> authorizationData;
    strMessages newMessages;
    strMessages readMessages;
    MainWindow* mainWindow;
    vmime::shared_ptr  <vmime::net::store> store ;
    vmime::shared_ptr <vmime::net::session> session;


public slots:
    void onLogin();

};

#endif // CONTROL_H
