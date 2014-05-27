#include "Email_Address_Retrieval_Application.h"
#include "QDebug"
#include "Interactive_Certificate_Verifier.hpp"

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

 EmailAddressRetrievalApplication::strMessages EmailAddressRetrievalApplication::getNewMasseges() {
    newMessages = fetchNewMessages(store);
    return newMessages;
 }

 EmailAddressRetrievalApplication::strMessages EmailAddressRetrievalApplication::getReadMasseges() {
    readMessages = fetchReadMessages(store);
    return readMessages;

 }

 void EmailAddressRetrievalApplication::deleteMsg(int &index)
 {
    folder->deleteMessages(vmime::net::messageSet::byNumber(index));
 }

 vmime::string EmailAddressRetrievalApplication::getImap() {
    QMap <QString,QString> singInData = mainWindow->getAutorizationCredentials();

    vmime::string imapURL ;
    imapURL.append("imaps://");
    imapURL.append(singInData["login"].toStdString());
    imapURL.append(":");
    imapURL.append(singInData["password"].toStdString());
    imapURL.append("@imap.gmail.com:993");

    return imapURL;
 }

bool EmailAddressRetrievalApplication::imapConnection(){
    session = vmime::make_shared<vmime::net::session>();
    vmime::utility::url url("imaps://savchenko.inc:BanderaMozli@imap.gmail.com:993");//vmime::utility::url url(getImap());

    store = session->getStore(url);
    store->setProperty("connection.tls", true);
    store->setTimeoutHandlerFactory(vmime::make_shared <timeoutHandlerFactory>());
    store->setCertificateVerifier (vmime::make_shared <interactiveCertificateVerifier>());

    vmime::shared_ptr <std::ostringstream> traceStream = vmime::make_shared <std::ostringstream>();

    store->setTracerFactory(vmime::make_shared <TracerFactory>(traceStream));
    store->connect();

    if(store->isConnected()){
      return true;
      }
    return false;
}

void EmailAddressRetrievalApplication::extractMsg() {

    vmime::shared_ptr <vmime::net::message> msg = folder->getMessage(9);
    vmime::utility::outputStreamAdapter out(std::cout);
    msg->extract(out);
}

 void EmailAddressRetrievalApplication::onLogin() {
    if(imapConnection()){

        showUserProfile();
        getNewMasseges();
        getReadMasseges();
        extractMsg();
        ShowMessages *window = new ShowMessages(newMessages.msgPart,newMessages.num, readMessages.msgPart,readMessages.num);
        window->show();
        mainWindow->hide();
    }
}

 EmailAddressRetrievalApplication::strMessages EmailAddressRetrievalApplication::fetchNewMessages(vmime::shared_ptr<vmime::net::store> &st){

    QList <QString> msgList;
    QList <int> numList;
    strMessages listOfMessages;
    vmime::shared_ptr <vmime::net::message> msg ;
    vmime::shared_ptr<const vmime::header> hdr ;

    folder = st->getDefaultFolder();
    folder->open(vmime::net::folder::MODE_READ_WRITE);
    const int count = folder->getMessageCount();

    for(int i = count; i>=1; i--){
         msg = folder->getMessage(i);
         folder->fetchMessage(msg, vmime::net::fetchAttributes::FLAGS| vmime::net::fetchAttributes::ENVELOPE);

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
    listOfMessages.msgPart = msgList;
    listOfMessages.num = numList;

    return listOfMessages;
 }

 EmailAddressRetrievalApplication::strMessages EmailAddressRetrievalApplication::fetchReadMessages(vmime::shared_ptr<vmime::net::store> &st) {

    QList <QString> msgList;
    QList <int> numList;
    strMessages listOfMessages;
    vmime::shared_ptr <vmime::net::message> msg ;
    vmime::shared_ptr<const vmime::header> hdr ;
    folder = st->getDefaultFolder();
    folder->open(vmime::net::folder::MODE_READ_WRITE);
    const int count = folder->getMessageCount();

    for(int i = count; i>=1; i--){
        msg = folder->getMessage(i);
        folder->fetchMessage(msg, vmime::net::fetchAttributes::FLAGS| vmime::net::fetchAttributes::ENVELOPE);

        if (msg->getFlags() & vmime::net::message::FLAG_SEEN){
           hdr = msg->getHeader();
           std::string strUtfFrom= hdr->From()->generate();
           QString strFrom = QString::fromUtf8(strUtfFrom.c_str());
           std::string strUtfDate= hdr->Date()->generate();
           QString strDate = QString::fromUtf8(strUtfDate.c_str());
           msgList.insert(i,strFrom+" - "+strDate);
           numList.insert(i,i);
        }
    }
    listOfMessages.msgPart = msgList;
    listOfMessages.num = numList;

    return listOfMessages;

 }

