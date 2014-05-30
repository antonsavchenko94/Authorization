#include "email_address_retrieval_application.h"
#include "QDebug"
#include <QDesktopWidget>


EmailAddressRetrievalApplication::EmailAddressRetrievalApplication() {}

int EmailAddressRetrievalApplication::exec(int argc, char *argv[]) {
    QApplication a(argc, argv);

    mainWindow = new MainWindow();
    mainWindow->show();
    setCentralOnDesktop();
    connect(mainWindow, SIGNAL(login(QMap<QString, QString> )), this,SLOT(onLogin(QMap<QString, QString>)));
    connect(this, SIGNAL(changeForm(QList<QString> &)), mainWindow,SLOT(onChangeForm(QList <QString>&)));
    return a.exec();
 }

void EmailAddressRetrievalApplication::onLogin(QMap<QString, QString>  user) {
    mainWindow->setCursor(Qt::WaitCursor);
    MailServer *gms = new MailServer (user);

    gms->imapConnection();
    QList<QString> list;
    list = gms->fetchMessages();
    emit changeForm(list);

    setCentralOnDesktop();
    mainWindow->setCursor(Qt::ArrowCursor);
}

void EmailAddressRetrievalApplication::setCentralOnDesktop()
{
  int x, y;
  int screenWidth;
  int screenHeight;

  QDesktopWidget *desktop = QApplication::desktop();

  screenWidth = desktop->width();
  screenHeight = desktop->height();

  x = (screenWidth - mainWindow->width()) / 2;
  y = (screenHeight - mainWindow->height()) / 2;

  mainWindow->setGeometry(x, y, mainWindow->width(), mainWindow->height());
}
