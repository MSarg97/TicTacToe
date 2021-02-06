#ifndef RESULT_H
#define RESULT_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

namespace Ui {
class Result;
}

class TicTacToeBoard;

class Result : public QWidget
{
    Q_OBJECT

public:
    explicit Result(QWidget *parent = nullptr);
    ~Result();

public slots:
    void getWinner(QString);
    void getEstimatedTime(QString);
    void yesButtonClicked();
    void noButtonClicked();

private:
    Ui::Result *ui;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QPushButton *yesButton;
    QPushButton *noButton;
    TicTacToeBoard *tttBoard;
};

#endif // RESULT_H
