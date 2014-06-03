#ifndef PARSER_OF_STRING_H
#define PARSER_OF_STRING_H

#include <QObject>
#include <gtest/gtest.h>

class ParserOfString : public QObject
{
  Q_OBJECT
public:
  explicit ParserOfString(QObject *parent = 0);

  QString parseToEmail(QString &str);
  QString parseByAuthor(QString &str);
  QString parseToLogin(QString &str);
signals:

public slots:

private:

};

#endif // PARSER_OF_STRING_H



