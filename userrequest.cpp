#include "userrequest.h"
#include "ui_userrequest.h"

UserRequest::UserRequest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserRequest)
{
    ui->setupUi(this);

    buttonX = new QPushButton();
    buttonO = new QPushButton();
    buttonAbout = new QPushButton();
    verticalLayout = new QVBoxLayout();
    horizontalLayout = new QHBoxLayout();

    setWindowTitle("User Request");
    setWindowFlag(Qt::Window);
    setStyleSheet("background-color: rgb(160, 160, 160);");

    buttonX->setText("X");
    buttonX->setStyleSheet("font: 75 12pt; background-color: rgb(255, 255, 255);");

    buttonO->setText("O");
    buttonO->setStyleSheet("font: 75 12pt; background-color: rgb(255, 255, 255);");

    buttonAbout->setText("About");
    buttonAbout->setStyleSheet("font: 75 12pt; background-color: rgb(255, 255, 255);");

    horizontalLayout->addWidget(buttonX);
    horizontalLayout->addWidget(buttonO);
    horizontalLayout->addWidget(buttonAbout);

    verticalLayout->addLayout(horizontalLayout);

    setLayout(verticalLayout);

    connect(buttonX, SIGNAL(pressed()), this, SLOT(buttonXPressed()));
    connect(buttonO, SIGNAL(pressed()), this, SLOT(buttonOPressed()));
    connect(this, SIGNAL(sendCharacter(QString)), parent, SLOT(getPlayerCharacter(QString)));
    connect(buttonAbout, SIGNAL(pressed()), this, SLOT(buttonAboutPressed()));
}

void UserRequest::buttonAboutPressed()
{
    QMessageBox::information(this, "About", "One Player Mode\nClick X if you agree: X - user, O - computer\n"
                                            "Click O if you agree: O - user, X - computer, user plays first\n\n"
                                            "Two Player Mode\nClick X if you agree: X - first user, O - second user\n"
                                            "Click O if you agree: O - first user, X - second user, user plays first\n",
                                            QMessageBox::Ok);
}


void UserRequest::buttonOPressed()
{
    emit sendCharacter(buttonO->text());
    close();
}


void UserRequest::buttonXPressed()
{
    emit sendCharacter(buttonX->text());
    close();
}


UserRequest::~UserRequest()
{
    delete ui;
}
