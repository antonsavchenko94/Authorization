#ifndef USER_PROFILE_H
#define USER_PROFILE_H

#include <QMainWindow>
#include <QMap>
#include <QLabel>
#include <QDebug>

#include "email_address_retrieval_application.h"

namespace Ui {
class User_Profile;
}

class User_Profile : public QMainWindow
{
    Q_OBJECT

public:
    void setTolabel(QLabel *);
    QList<QString> setData;
    QList<int>  setNum;
    explicit User_Profile(QList<QString> &data,QList<int> &num, QWidget *parent = 0);

    ~User_Profile();

private slots:
    void on_listWidget_activated(const QModelIndex &index);

    void on_listWidget_clicked(const QModelIndex &index);

    void on_pushButton_clicked();

private:

    Ui::User_Profile *ui;
    QList<QString> &data_;
    QList <int> &num_;
    void setIndex(int &index);
    int msgIndex;

};

#endif // USER_PROFILE_H
