#include "parser_of_string.h"
#include <QRegExp>
#include <QDebug>


ParserOfString::ParserOfString(QObject *parent) :
  QObject(parent)
{

}

QString ParserOfString::parseToEmail(QString &str){
  QString value;
  QRegExp rxlen("(\x3C.*\x3E)");

  if(str.contains(rxlen)){
  rxlen.indexIn(str);
  value = rxlen.cap(1);
  value.remove('<');
  value.remove('>');
  return value;
    }else{
      QRegExp rxEls ("(^.*$)");
      rxEls.indexIn(str);
      value = rxEls.cap(1);
      value.remove("From:");
      return value;
    }
}

QString ParserOfString::parseByAuthor(QString &str){
  QString value;
  QRegExp rxlen("(\x20.*\x20)");
  if(str.contains(rxlen)){
    rxlen.indexIn(str);
    value = rxlen.cap(1);
    value.remove(' ');
    value.remove('"');

    return value;
}else
  return value = " None name";
}

QString ParserOfString::parseToLogin(QString &str){
  QString value;
  QRegExp rxlen("(^[-a-z0-9!#$%&'*+/=?^_`{|}~]+(\.[-a-z0-9!#$%&'*+/=?^_`{|}~]+)*@)");
  rxlen.indexIn(str);
  value = rxlen.cap(1);
  value.remove("@");
  return value;

}


