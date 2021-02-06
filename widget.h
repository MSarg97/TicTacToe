#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QPushButton>
#include <QVBoxLayout>
#include <QProgressBar>
#include <QTimer>
#include "tictactoeboard.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);

    ~Widget();

public slots:
    void startButtonClicked();
    void increment();    

private:
    Ui::Widget *ui;
    QTimer *timer;
    QPushButton *startButton;
    QVBoxLayout *verticalLayout;
    QProgressBar *progressBar;
    TicTacToeBoard *tictactoeBoard;
};
#endif // WIDGET_H
