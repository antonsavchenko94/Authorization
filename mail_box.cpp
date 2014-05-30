#include "mail_box.h"
#include "ui_mail_box.h"

MailBox::MailBox(QList <QString>headers, QWidget *parent) :
  QWidget(parent),
  ui(new Ui::MailBox),
  headers_(headers)
{
  ui->setupUi(this);
  setHeadersToTextEdit(headers_);
}

MailBox::~MailBox()
{
  delete ui;
}

void MailBox::setHeadersToTextEdit(QList <QString> &headers){
  int size = headers.size();
  for(int i=0; i<=size-1; i++){
      ui->textEdit->append(headers[i]+"\n");
     }
}

