#include "mail_server.h"
#include "time_out_handler.h"
#include "tracer.h"
#include "interactive_certificate_verifier.hpp"

#include <QString>
#include <QRegExp>
#include <QDebug>

MailServer::MailServer(QMap<QString, QString> &user) : userData_(user){
  setUserData(userData_);
}

QList <QString>  MailServer::fetchMessages(){
  QList <QString> msgList;
  vmime::shared_ptr <vmime::net::message> msg ;
  vmime::shared_ptr<const vmime::header> hdr ;

  folder = store->getDefaultFolder();
  folder->open(vmime::net::folder::MODE_READ_WRITE);
  const int count = folder->getMessageCount();
  for(int i = count; i>=1; i--){
        msg = folder->getMessage(i);
        folder->fetchMessage(msg, vmime::net::fetchAttributes::FLAGS| vmime::net::fetchAttributes::ENVELOPE);
        msg->getFlags();
        hdr = msg->getHeader();
        std::string strUtfFrom= hdr->From()->generate();
        QString strFrom = QString::fromUtf8(strUtfFrom.c_str());
        msgList.insert(i,strFrom);
  }
  return msgList;
}

bool MailServer::imapConnection(){
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

QMap<QString, QString> MailServer::getUserData() const{
  return userData;
}

void MailServer::setUserData(const QMap<QString, QString> &value){
  userData = value;
}

vmime::string MailServer::getImap(){
  QMap<QString, QString> loginPassword = getUserData();

  vmime::string imapString;
  imapString.append("imaps://");
  imapString.append(loginPassword["login"].toStdString());
  imapString.append(":");
  imapString.append(loginPassword["password"].toStdString());
  imapString.append("@imap.gmail.com:993");

  return imapString;
}
