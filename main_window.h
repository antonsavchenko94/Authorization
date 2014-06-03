#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mail_box.h"
#include "parser_of_string.h"
#include <QRegExpValidator>
#include <QMainWindow>
#include <QValidator>
#include <QTextEdit>
#include <QRegExp>
#include <QMap>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QMap<QString,QString> getAutorizationCredentials();

signals:
    void login(QMap<QString, QString> user);

public slots:
   void onChangeForm(QList<QString> &headers);


private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QTextEdit* textEdit;
    QList<QString> headers_;

};

#endif // MAINWINDOW_H
