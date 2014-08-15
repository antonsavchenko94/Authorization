#ifndef MAIL_VIEWER_H
#define MAIL_VIEWER_H

#include <QWidget>

namespace Ui {
  class Mailviewer;
}

class Mailviewer : public QWidget
{
  Q_OBJECT

public:
  explicit Mailviewer(QWidget *parent = 0);
  ~Mailviewer();

private:
  Ui::Mailviewer *ui;
};

#endif // MAIL_VIEWER_H
