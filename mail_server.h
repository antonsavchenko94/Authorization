#ifndef MAIL_SERVER_H
#define MAIL_SERVER_H

#include <vmime/net/store.hpp>
#include <vmime/vmime.hpp>
#include <QList>
#include <QMap>

#include <parser_of_string.h>

class MailServer
{
  struct strMessages
  {
      QList <int>  num;
      QList <QString> msgPart;
  };

public:
  void setUserData(const QMap<QString, QString> &value);
  QMap<QString, QString> getUserData() const;
  MailServer(QMap<QString,QString> &user);
  QList<QString> fetchMessages();
  strMessages getMasseges();
  bool imapConnection();

  vmime::shared_ptr <vmime::net::folder> folder;
  QMap<QString, QString> userData;

private:
  vmime::shared_ptr  <vmime::net::store> store ;
  vmime::shared_ptr <vmime::net::session> session;
  QMap<QString, QString> userData_;
  ParserOfString* parser;

  vmime::string getImap();
  QString parsing(QString &str);

};

#endif // MAIL_SERVER_H
