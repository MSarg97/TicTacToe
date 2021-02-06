#include "result.h"
#include "ui_result.h"
#include "tictactoeboard.h"

Result::Result(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Result)
{
    ui->setupUi(this);

    setWindowTitle("Result");
    setWindowFlag(Qt::Window);

    verticalLayout = new QVBoxLayout();
    horizontalLayout = new QHBoxLayout();
    label = new QLabel();
    yesButton = new QPushButton();
    noButton = new QPushButton();

    yesButton->setText("Yes");
    noButton->setText("No");

    setStyleSheet("background-color: rgb(160, 160, 160);");
    label->setStyleSheet("font: 8pt \"MS Shell Dlg 2\"");
    noButton->setStyleSheet("font: 75 12pt; background-color: rgb(255, 255, 255);");
    yesButton->setStyleSheet("font: 75 12pt; background-color: rgb(255, 255, 255);");

    horizontalLayout->addWidget(yesButton);
    horizontalLayout->addWidget(noButton);
    verticalLayout->addWidget(label);
    verticalLayout->addLayout(horizontalLayout);
    setLayout(verticalLayout);

    connect(yesButton, SIGNAL(clicked()), this, SLOT(yesButtonClicked()));
    connect(noButton, SIGNAL(clicked()), this, SLOT(noButtonClicked()));
}


void Result::getWinner(QString winner)
{
    if(!winner.compare(" "))
        label->setText("Tie!");
    else
        label->setText(winner + " won!");
}


void Result::getEstimatedTime(QString estTime)
{
    label->setText(label->text() + "\nEstimated time: " + estTime + "\n\n\nDo you want to start the game?");
}


void Result::yesButtonClicked()
{
    close();
    tttBoard = new TicTacToeBoard();
    tttBoard->show();
}


void Result::noButtonClicked()
{
    close();
}


Result::~Result()
{
    delete ui;
}
