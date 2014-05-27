#include "Show_Messages.h"
#include "ui_user_profile.h"
#include <QDebug>

ShowMessages::ShowMessages(QList<QString> &newMsg, QList<int> &newNum, QList<QString> &readMsg, QList<int> &readNum, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ShowMessages),
    newMsg_(newMsg),
    newNum_(newNum),
    readMsg_(readMsg),
    readNum_(readNum)
{
    setNewMsg = newMsg_;
    setNewNum = newNum_;
    setReadMsg = readMsg_;
    setReadNum = readNum_;

    ui->setupUi(this);
    ui->pushButton->setDisabled(false);
    setToNewMsg();
    setToReadMsg();
}
ShowMessages::~ShowMessages(){
    delete ui;
}

void ShowMessages::on_pushButton_clicked() {
}

void ShowMessages::setIndex(int &index){
  msgIndex = index;
}

int ShowMessages::getIndex() {
  QModelIndex index;
  index = ui->listWidget->currentIndex();
  int i = index.row();
  qDebug()<<"i== "<<i;
  return i;
}

void ShowMessages::setToNewMsg(){
  for (int i = setNewMsg.size() -1; i>=0; i--)
      ui->listWidget->addItem(setNewMsg.at(i));
}

void ShowMessages::setToReadMsg(){
  for (int i = setReadMsg.size() -1; i>=0; i--)
      ui->listWidget_2->addItem(setReadMsg.at(i));
}

//void ShowMessages::on_openMessages_clicked(){
//    int i = getIndex();
//    i++
//}
