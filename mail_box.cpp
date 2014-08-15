#include "mail_box.h"
#include "ui_mail_box.h"

MailBox::MailBox(QList <QString>headers, QMainWindow* mainWindow, QWidget *parent) :
  QWidget(parent),
  ui(new Ui::MailBox),
  headers_(headers),
  mainWindow_(mainWindow)
{
  ui->setupUi(this);
  setHeadersToTextEdit();
}

MailBox::~MailBox()
{
  delete ui;
}

void MailBox::setHeadersToTextEdit(){
  int size = headers_.size();
  for(int i=0; i<=size-1; i++){
      ui->listWidget->addItem(headers_[i]);
     }
}


void MailBox::on_pushButton_clicked()
{
  Mailviewer* mv = new Mailviewer();
  resize(mv->width(),mv->height());
  //MailServer::openMessage(2);
  mainWindow_->setCentralWidget(mv);

}
