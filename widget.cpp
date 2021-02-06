#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    setWindowTitle("Start Tic Tac Toe");
    setStyleSheet("background-color: rgb(160, 160, 160);");

    timer = new QTimer();
    progressBar = new QProgressBar();
    startButton = new QPushButton();
    verticalLayout = new QVBoxLayout();

    startButton->setStyleSheet("font: 75 12pt; background-color: rgb(255, 255, 255);");
    startButton->setText("Start");

    connect(startButton, SIGNAL(pressed()), this, SLOT(startButtonClicked()));

    verticalLayout->addWidget(startButton);
    verticalLayout->addWidget(progressBar);
    setLayout(verticalLayout);
}


void Widget::startButtonClicked()
{
    startButton->setEnabled(false);

    progressBar->setMinimum(0);
    progressBar->setMaximum(100);

    connect(timer, SIGNAL(timeout()), this, SLOT(increment()));
    timer->start(100);
}


void Widget::increment()
{
    if(progressBar->value() == progressBar->maximum())
    {
        timer->stop();

        tictactoeBoard = new TicTacToeBoard();
        tictactoeBoard->show();
        close();
    }

    setWindowTitle("Progress - " + QString::number(progressBar->value()) + "%");
    progressBar->setValue(progressBar->value() + 1);
}


Widget::~Widget()
{
    delete ui;
}
