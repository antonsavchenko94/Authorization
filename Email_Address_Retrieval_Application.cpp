#include "email_address_retrieval_application.h"
#include "QDebug"
#include "interactiveCertificateVerifier.hpp"

EmailAddressRetrievalApplication::EmailAddressRetrievalApplication() {}

int EmailAddressRetrievalApplication::exec(int argc, char *argv[]) {
    QApplication a(argc, argv);

    mainWindow = new MainWindow();
    mainWindow->show();
    connect(mainWindow, SIGNAL(login()), this,SLOT(onLogin()));

    return a.exec();
 }

 QMap<QString, QString> EmailAddressRetrievalApplication::showUserProfile() {
    authorizationData = mainWindow->getAutorizationCredentials();
    return authorizationData;
 }

 EmailAddressRetrievalApplication::strMassages EmailAddressRetrievalApplication::setMasseges() {
     massages = fetchMassages(store);
     return massages;
 }

 vmime::string EmailAddressRetrievalApplication::getImap() {
    QMap <QString,QString> singInData = mainWindow->getAutorizationCredentials();

    vmime::string imapURL ;
    imapURL.append("imaps://");
    imapURL.append(singInData["login"].toStdString());
    imapURL.append(":");
    imapURL.append(singInData["password"].toStdString());
    imapURL.append("@imap.gmail.com:993");
// //////////
    return imapURL;
 }

 bool EmailAddressRetrievalApplication::imapConnection()
 {
     session = vmime::make_shared<vmime::net::session>();
     vmime::utility::url url(getImap());//vmime::utility::url url("imaps://savchenko.inc:BanderaMozli@imap.gmail.com:993");


     store = session->getStore(url);
     store->setProperty("connection.tls", true);
     store->setTimeoutHandlerFactory(vmime::make_shared <timeoutHandlerFactory>());
     store->setCertificateVerifier (vmime::make_shared <interactiveCertificateVerifier>());

     vmime::shared_ptr <std::ostringstream> traceStream = vmime::make_shared <std::ostringstream>();

     store->setTracerFactory(vmime::make_shared <myTracerFactory>(traceStream));
     store->connect();

     if(store->isConnected()){
         return false;
     }

 }

 void EmailAddressRetrievalApplication::onLogin() {


    if(imapConnection()){

        showUserProfile();
        setMasseges();
        User_Profile *window = new User_Profile(massages.msgPart,massages.num);
        window->show();
        mainWindow->hide();
    }
}

 EmailAddressRetrievalApplication::strMassages EmailAddressRetrievalApplication::fetchMassages(vmime::shared_ptr<vmime::net::store> &st)
 {

    vmime::shared_ptr <vmime::net::folder> f;
    QList <QString> msgList;
    QList <int> numList;
    strMassages listOfMassages;
    vmime::shared_ptr <vmime::net::message> msg ;
    vmime::shared_ptr<const vmime::header> hdr ;

    f = st->getDefaultFolder();
    f->open(vmime::net::folder::MODE_READ_WRITE);
    const int count = f->getMessageCount();

    for(int i = count; i>=1; i--){
         msg = f->getMessage(i);
         f->fetchMessage(msg, vmime::net::fetchAttributes::FLAGS| vmime::net::fetchAttributes::ENVELOPE);

         if (msg->getFlags()!=vmime::net::message::FLAG_SEEN){
            hdr = msg->getHeader();

            std::string strUtfFrom= hdr->From()->generate();
            QString strFrom = QString::fromUtf8(strUtfFrom.c_str());
            std::string strUtfDate= hdr->Date()->generate();
            QString strDate = QString::fromUtf8(strUtfDate.c_str());
            msgList.insert(i,strFrom+" - "+strDate);
            numList.insert(i,i);
         }
     }
     listOfMassages.msgPart = msgList;
     listOfMassages.num = numList;

     return listOfMassages;
 }

