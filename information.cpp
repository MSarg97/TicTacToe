#include "information.h"
#include "ui_information.h"

Information::Information(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Information)
{
    ui->setupUi(this);

    setWindowFlag(Qt::Window);
    setWindowTitle("Information");

    label = new QLabel();
    okButton = new QPushButton();
    verticalLayout = new QVBoxLayout();

    label->setText("Please, first choose the number of players and the character!");
    okButton->setText("OK");

    setStyleSheet("background-color: rgb(160, 160, 160);");

    label->setStyleSheet("font: 8pt \"MS Shell Dlg 2\";");
    okButton->setStyleSheet("font: 10pt \"MS Shell Dlg 2\"; background-color: rgb(255, 255, 255);");

    verticalLayout->addWidget(label);
    verticalLayout->addWidget(okButton);

    setLayout(verticalLayout);

    connect(okButton, SIGNAL(pressed()), this, SLOT(okButtonPressed()));
}


void Information::okButtonPressed()
{
    close();
}


Information::~Information()
{
    delete ui;
}
