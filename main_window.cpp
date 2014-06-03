#include "main_window.h"
#include "ui_mainwindow.h"
#include "email_address_retrieval_application.h"

#include <QDebug>
#include <QKeyEvent>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->ePassword->setEchoMode(QLineEdit::Password);
}

MainWindow::~MainWindow() {
    delete ui;
}

QMap<QString, QString> MainWindow::getAutorizationCredentials(){
    ParserOfString pos;
    QMap<QString, QString> tableData;
    QString login ;
    login = ui->eLogin->text();
    login = pos.parseToLogin(login);
    tableData.insert("login", login);
    tableData.insert("password",ui->ePassword->text());
    return tableData;
}

void MainWindow::onChangeForm(QList<QString> &headers){
  setWindowTitle("Email Box");
  MailBox* mb = new MailBox(headers);
  resize(mb->width(),mb->height());
  setCentralWidget(mb);
}

void MainWindow::on_pushButton_clicked(){
  emit login(getAutorizationCredentials());
}
