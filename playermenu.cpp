#include "playermenu.h"
#include "ui_playermenu.h"

PlayerMenu::PlayerMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlayerMenu)
{
    ui->setupUi(this);
    setWindowTitle("Menu");
    setWindowFlag(Qt::Window);

    setStyleSheet("background-color: rgb(160, 160, 160);");

    label = new QLabel();
    firstPushButton = new QPushButton();
    aboutOnePlayer = new QPushButton();
    secondPushButton = new QPushButton();
    aboutTwoPlayers = new QPushButton();
    verticalLayout = new QVBoxLayout();

    label->setText("Menu");
    label->setFixedHeight(40);
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("font: 75 24pt; background-color: rgb(255, 255, 255);");

    firstPushButton->setText("One Player");
    firstPushButton->setStyleSheet("font: 75 12pt; background-color: rgb(255, 255, 255);");

    aboutOnePlayer->setText("About One Player");
    aboutOnePlayer->setStyleSheet("font: 75 12pt; background-color: rgb(255, 255, 255);");

    secondPushButton->setText("Two Players");
    secondPushButton->setStyleSheet("font: 75 12pt; background-color: rgb(255, 255, 255);");

    aboutTwoPlayers->setText("About Two Players");
    aboutTwoPlayers->setStyleSheet("font: 75 12pt; background-color: rgb(255, 255, 255);");

    verticalLayout->addWidget(label);
    verticalLayout->addWidget(firstPushButton);
    verticalLayout->addWidget(aboutOnePlayer);
    verticalLayout->addWidget(secondPushButton);
    verticalLayout->addWidget(aboutTwoPlayers);

    setLayout(verticalLayout);

    connect(this, SIGNAL(sendNumber(int)), parent, SLOT(getPlayerNumber(int)));
    connect(firstPushButton, SIGNAL(pressed()), this, SLOT(onePlayerButtonClicked()));
    connect(aboutOnePlayer, SIGNAL(pressed()), this, SLOT(aboutOnePlayerClicked()));
    connect(secondPushButton, SIGNAL(pressed()), this, SLOT(twoPlayerButtonClicked()));
    connect(aboutTwoPlayers, SIGNAL(pressed()), this, SLOT(aboutTwoPlayersClicked()));
}


void PlayerMenu::onePlayerButtonClicked()
{    
    emit sendNumber(1);
    close();
}


void PlayerMenu::aboutOnePlayerClicked()
{
    QMessageBox::information(this, "About One Player", "Click One Player if you want to play with computer", QMessageBox::Ok);
}


void PlayerMenu::twoPlayerButtonClicked()
{
    emit sendNumber(2);
    close();
}


void PlayerMenu::aboutTwoPlayersClicked()
{
    QMessageBox::information(this, "About Two Players", "Click Two Players if you want to play with your friend", QMessageBox::Ok);
}


PlayerMenu::~PlayerMenu()
{
    delete ui;
}
