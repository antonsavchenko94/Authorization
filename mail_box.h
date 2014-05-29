#ifndef MAIL_BOX_H
#define MAIL_BOX_H

#include <QWidget>

namespace Ui {
  class MailBox;
}

class MailBox : public QWidget
{
  Q_OBJECT

public:
  explicit MailBox( QList <QString>headers, QWidget *parent = 0);
  ~MailBox();

private:
  Ui::MailBox *ui;
  QList<QString> headers_;

  void setHeadersToTextEdit(QList<QString> &headers);
};

#endif // MAIL_BOX_H
