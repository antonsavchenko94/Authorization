#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QRegExpValidator>
#include <QMainWindow>
#include <QValidator>
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
    void login();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_lineEdit_3_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
