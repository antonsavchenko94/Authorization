#include "email_address_retrieval_application.h"
#include "QDebug"


EmailAddressRetrievalApplication::EmailAddressRetrievalApplication() {}

int EmailAddressRetrievalApplication::exec(int argc, char *argv[]) {
    QApplication a(argc, argv);

    mainWindow = new MainWindow();
    mainWindow->show();
    connect(mainWindow, SIGNAL(login(QMap<QString, QString> )), this,SLOT(onLogin(QMap<QString, QString>)));
    connect(this, SIGNAL(changeForm(QList<QString> &)), mainWindow,SLOT(onChangeForm(QList <QString>&)));
    return a.exec();
 }

void EmailAddressRetrievalApplication::onLogin(QMap<QString, QString>  user) {
    MailServer *gms = new MailServer (user);
    mainWindow->setCursor(Qt::WaitCursor);
    gms->imapConnection();
    QList<QString> list;
    list = gms->fetchMessages();
    emit changeForm(list);
    mainWindow->setCursor(Qt::ArrowCursor);
}
