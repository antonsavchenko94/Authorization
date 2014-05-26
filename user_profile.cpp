#include "user_profile.h"
#include "ui_user_profile.h"
#include <QDebug>

User_Profile::User_Profile(QList<QString> &data, QList<int> &num, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::User_Profile),
    data_(data),
    num_(num)
{
    setData = data_;
    setNum = num_;

    ui->setupUi(this);

    for (int i = setData.size() -1; i>=0; i--)
        ui->listWidget->addItem(setData.at(i));

    ui->pushButton->setDisabled(true);
}
User_Profile::~User_Profile(){
    delete ui;
}

void User_Profile::on_listWidget_clicked(const QModelIndex &index){
    ui->pushButton->setEnabled(true);
}



void User_Profile::on_pushButton_clicked(){
    //folder->deleteMessages(vmime::net::messageSet::byNumber(2));
}

void User_Profile::setIndex(int &index){
    msgIndex = index;
}

