#ifndef CONTROL_H
#define CONTROL_H

#include <QObject>
#include <QMap>
#include <QString>
#include <functional>
#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <QApplication>

#include <vmime/vmime.hpp>
#include <vmime/net/session.hpp>
#include <vmime/net/store.hpp>
#include <vmime/utility/url.hpp>

#include "memory.h"
#include "timeoutHandler.h"
#include "tracer.h"
#include "user_profile.h"
#include "mainwindow.h"

class EmailAddressRetrievalApplication: public QObject
{
    Q_OBJECT

struct strMassages
{
    QList <int>  num;
    QList <QString> msgPart;
};

public:
   EmailAddressRetrievalApplication();

    int exec(int argc, char *argv[]);
    QMap <QString,QString> showUserProfile();    
    strMassages fetchMassages(vmime::shared_ptr  <vmime::net::store>&st);
    strMassages setMasseges();
    vmime::string getImap();
    bool imapConnection();
private:
    QMap <QString,QString> authorizationData;
    strMassages massages;
    MainWindow* mainWindow;
    vmime::shared_ptr  <vmime::net::store> store ;
    vmime::shared_ptr <vmime::net::session> session;

public slots:
    void onLogin();

};

#endif // CONTROL_H
