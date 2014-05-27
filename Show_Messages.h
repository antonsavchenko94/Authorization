#ifndef ShowMessages_H
#define ShowMessages_H

#include <QMainWindow>
#include <QMap>
#include <QLabel>
#include <QDebug>


namespace Ui {
class ShowMessages;
}

class ShowMessages : public QMainWindow
{
    Q_OBJECT

public:

    QList<QString> setNewMsg;
    QList<QString> setReadMsg;
    QList<int>  setReadNum;
    QList<int>  setNewNum;

    explicit ShowMessages(QList<QString> &newMsg, QList<int> &newNum, QList<QString> &readMsg, QList<int> &readNum, QWidget *parent = 0);

    ~ShowMessages();

private slots:
    void on_listWidget_activated(const QModelIndex &index);

    void on_listWidget_clicked(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_openMessages_clicked();

private:

    void setIndex(int &index);
    int getIndex();
    void setToNewMsg ();
    void setToReadMsg ();

    Ui::ShowMessages *ui;
    QList<QString> &newMsg_;
    QList<int> &newNum_;
    QList<QString> &readMsg_;
    QList<int> &readNum_;
    int msgIndex;

};

#endif // ShowMessages_H
