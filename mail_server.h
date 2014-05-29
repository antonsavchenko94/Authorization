#ifndef MAIL_SERVER_H
#define MAIL_SERVER_H

#include <vmime/net/store.hpp>
#include <vmime/vmime.hpp>
#include <QList>
#include <QMap>

class MailServer
{
  struct strMessages
  {
      QList <int>  num;
      QList <QString> msgPart;
  };

public:
  MailServer(QMap<QString,QString> &user);

  QList<QString> fetchMessages();
  strMessages getMasseges();
  bool imapConnection();
  vmime::shared_ptr <vmime::net::folder> folder;
  QMap<QString, QString> userData;

  QMap<QString, QString> getUserData() const;
  void setUserData(const QMap<QString, QString> &value);

private:
  vmime::shared_ptr  <vmime::net::store> store ;
  vmime::shared_ptr <vmime::net::session> session;
  QMap<QString, QString> userData_;
  vmime::string getImap();

};

#endif // MAIL_SERVER_H
