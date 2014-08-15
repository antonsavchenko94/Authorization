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
  MailServer(QMap<QString,QString> &user);

  void setUserData(const QMap<QString, QString> &value);
  QMap<QString, QString> getUserData() const;
  QList<QString> fetchMessages();
  static QString openMessage(int num);
  strMessages getMasseges();
  bool imapConnection();
  vmime::string getImap();
  QString parsing(QString &str);

  vmime::shared_ptr <vmime::net::folder> folder;
  QMap<QString, QString> userData;

private:
  vmime::shared_ptr  <vmime::net::store> store ;
  vmime::shared_ptr <vmime::net::session> session;
  QMap<QString, QString> userData_;
  ParserOfString* parser;
};

#endif // MAIL_SERVER_H
