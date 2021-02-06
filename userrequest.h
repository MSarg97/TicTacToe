#ifndef USERREQUEST_H
#define USERREQUEST_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>

namespace Ui {
class UserRequest;
}

class UserRequest : public QWidget
{
    Q_OBJECT

public:
    explicit UserRequest(QWidget *parent = nullptr);
    ~UserRequest();

public slots:
    void buttonXPressed();
    void buttonOPressed();
    void buttonAboutPressed();

signals:
    void sendCharacter(QString);

private:
    Ui::UserRequest *ui;

    QPushButton *buttonAbout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *buttonX;
    QPushButton *buttonO;
};

#endif // USERREQUEST_H
