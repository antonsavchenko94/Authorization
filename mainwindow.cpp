#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "email_address_retrieval_application.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QMap<QString, QString> MainWindow::getAutorizationCredentials()
{
    QMap<QString, QString> tableData;
    tableData.insert("login",ui->eLogin->text());
    tableData.insert("password",ui->ePassword->text());
    return tableData;
}

void MainWindow::on_pushButton_clicked()
{
    emit login();
}
