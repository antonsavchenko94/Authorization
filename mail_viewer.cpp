#include "mail_viewer.h"
#include "ui_mail_viewer.h"

Mailviewer::Mailviewer(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Mailviewer)
{
  ui->setupUi(this);
}

Mailviewer::~Mailviewer()
{
  delete ui;
}
