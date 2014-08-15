#ifndef MAIL_BOX_H
#define MAIL_BOX_H

#include <QWidget>
#include <QMainWindow>

#include "mail_viewer.h"
#include "main_window.h"
#include "mail_server.h"


namespace Ui {
  class MailBox;
}

class MailBox : public QWidget
{
  Q_OBJECT

public:
  explicit MailBox( QList <QString>headers, QMainWindow* mainWindow, QWidget *parent = 0);
  ~MailBox();

private slots:
  void on_pushButton_clicked();

private:
  Ui::MailBox *ui;
  QList<QString> headers_;
  QMainWindow* mainWindow_;

  void setHeadersToTextEdit();
};

#endif // MAIL_BOX_H
