#ifndef TICTACTOEBOARD_H
#define TICTACTOEBOARD_H

#include <QWidget>
#include <QTime>
#include <QTimer>
#include <QDebug>
#include <QShowEvent>
#include "userrequest.h"
#include "playermenu.h"
#include "information.h"
#include "result.h"

namespace Ui {
class TicTacToeBoard;
}

class TicTacToeBoard : public QWidget
{
    Q_OBJECT

public:
    explicit TicTacToeBoard(QWidget *parent = nullptr);
    bool checkWin();
    bool isBoardFull();
    void enableBoard();
    void computerMove();
    void disableBoard();
    void setBoardColor();
    int minimax(int, bool);
    int getMax(int, int);
    int getMin(int, int);
    int getMoveValue();
    int findBestMove();
    ~TicTacToeBoard();

private slots:
    void on_pushButton1_pressed();
    void on_pushButton2_pressed();
    void on_pushButton3_pressed();
    void on_pushButton4_pressed();
    void on_pushButton5_pressed();
    void on_pushButton6_pressed();
    void on_pushButton7_pressed();
    void on_pushButton8_pressed();
    void on_pushButton9_pressed();
    void on_characterButton_pressed();
    void on_numberButton_pressed();
    void getPlayerCharacter(QString);
    void getPlayerNumber(int);
    void printTime();
    bool getTicTacToeResult();

signals:
    void sendWinner(QString);
    void sendEstimatedTime(QString);

private:
    Ui::TicTacToeBoard *ui;
    bool isCharButtonPressed;
    bool isNumButtonPressed;
    QString board[3][3];
    int currentPlayer;
    int playerNumber;

    QString userCharacter;
    QString secondUserCharacter;
    UserRequest *userRequestWindow;
    PlayerMenu *playerMenuWindow;

    Information *infoWindow;
    Result *resultWindow;
    QTime time;
    QTimer *timer;
};

#endif // TICTACTOEBOARD_H
