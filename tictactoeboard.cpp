#include "tictactoeboard.h"
#include "ui_tictactoeboard.h"

TicTacToeBoard::TicTacToeBoard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TicTacToeBoard)
{
    ui->setupUi(this);

    setWindowTitle("TicTacToe Board");

    setStyleSheet("background-color: rgb(160, 160, 160);");
    ui->numberButton->setStyleSheet("background-color: rgb(255, 255, 255);");
    ui->characterButton->setStyleSheet("background-color: rgb(255, 255, 255);");

    userRequestWindow = new UserRequest(this);
    playerMenuWindow = new PlayerMenu(this);
    resultWindow = new Result();
    infoWindow = new Information(this);

    time = QTime(0, 0);
    timer = new QTimer(this);

    isNumButtonPressed = false;
    isCharButtonPressed = false;
    currentPlayer = 0;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = "_";

    disableBoard();
    setBoardColor();
    printTime();

    infoWindow->show();

    connect(timer, SIGNAL(timeout()), this, SLOT(printTime()));
    connect(this, SIGNAL(sendWinner(QString)), resultWindow, SLOT(getWinner(QString)));
    connect(this, SIGNAL(sendEstimatedTime(QString)), resultWindow, SLOT(getEstimatedTime(QString)));
}


void TicTacToeBoard::on_pushButton1_pressed()
{
    if(board[0][0] == "_")
    {
        if(currentPlayer % 2 == 0)
        {
            ui->pushButton1->setText(userCharacter);
            board[0][0] = userCharacter;
        }
        else
        {
            ui->pushButton1->setText(secondUserCharacter);
            board[0][0] = secondUserCharacter;
        }

        currentPlayer++;

        if(!getTicTacToeResult())
        {
            if(playerNumber == 1)
                computerMove();
        }
    }
}


void TicTacToeBoard::on_pushButton2_pressed()
{
    if(board[0][1] == "_")
    {
        if(currentPlayer % 2 == 0)
        {
            ui->pushButton2->setText(userCharacter);
            board[0][1] = userCharacter;
        }
        else
        {
            ui->pushButton2->setText(secondUserCharacter);
            board[0][1] = secondUserCharacter;
        }

        currentPlayer++;

        if(!getTicTacToeResult())
        {
            if(playerNumber == 1)
                computerMove();
        }
    }
}


void TicTacToeBoard::on_pushButton3_pressed()
{
    if(board[0][2] == "_")
    {
        if(currentPlayer % 2 == 0)
        {
            ui->pushButton3->setText(userCharacter);
            board[0][2] = userCharacter;
        }
        else
        {
            ui->pushButton3->setText(secondUserCharacter);
            board[0][2] = secondUserCharacter;
        }

        currentPlayer++;

        if(!getTicTacToeResult())
        {
            if(playerNumber == 1)
                computerMove();
        }
    }
}


void TicTacToeBoard::on_pushButton4_pressed()
{
    if(board[1][0] == "_")
    {
        if(currentPlayer % 2 == 0)
        {
            ui->pushButton4->setText(userCharacter);
            board[1][0] = userCharacter;
        }
        else
        {
            ui->pushButton4->setText(secondUserCharacter);
            board[1][0] = secondUserCharacter;
        }

        currentPlayer++;

        if(!getTicTacToeResult())
        {
            if(playerNumber == 1)
                computerMove();
        }
    }
}


void TicTacToeBoard::on_pushButton5_pressed()
{
    if(board[1][1] == "_")
    {
        if(currentPlayer % 2 == 0)
        {
            ui->pushButton5->setText(userCharacter);
            board[1][1] = userCharacter;
        }
        else
        {
            ui->pushButton5->setText(secondUserCharacter);
            board[1][1] = secondUserCharacter;
        }

        currentPlayer++;

        if(!getTicTacToeResult())
        {
            if(playerNumber == 1)
                computerMove();
        }
    }
}


void TicTacToeBoard::on_pushButton6_pressed()
{
    if(board[1][2] == "_")
    {
        if(currentPlayer % 2 == 0)
        {
            ui->pushButton6->setText(userCharacter);
            board[1][2] = userCharacter;
        }
        else
        {
            ui->pushButton6->setText(secondUserCharacter);
            board[1][2] = secondUserCharacter;
        }

        currentPlayer++;

        if(!getTicTacToeResult())
        {
            if(playerNumber == 1)
                computerMove();
        }
    }
}


void TicTacToeBoard::on_pushButton7_pressed()
{
    if(board[2][0] == "_")
    {
        if(currentPlayer % 2 == 0)
        {
            ui->pushButton7->setText(userCharacter);
            board[2][0] = userCharacter;
        }
        else
        {
            ui->pushButton7->setText(secondUserCharacter);
            board[2][0] = secondUserCharacter;
        }
        currentPlayer++;

        if(!getTicTacToeResult())
        {
            if(playerNumber == 1)
                computerMove();
        }
    }
}


void TicTacToeBoard::on_pushButton8_pressed()
{
    if(board[2][1] == "_")
    {
        if(currentPlayer % 2 == 0)
        {
            ui->pushButton8->setText(userCharacter);
            board[2][1] = userCharacter;
        }
        else
        {
            ui->pushButton8->setText(secondUserCharacter);
            board[2][1] = secondUserCharacter;
        }
        currentPlayer++;

        if(!getTicTacToeResult())
        {
            if(playerNumber == 1)
                computerMove();
        }
    }
}


void TicTacToeBoard::on_pushButton9_pressed()
{
    if(board[2][2] == "_")
    {
        if(currentPlayer % 2 == 0)
        {
            ui->pushButton9->setText(userCharacter);
            board[2][2] = userCharacter;
        }
        else
        {
            ui->pushButton9->setText(secondUserCharacter);
            board[2][2] = secondUserCharacter;
        }
        currentPlayer++;

        if(!getTicTacToeResult())
        {
            if(playerNumber == 1)
                computerMove();
        }
    }
}


void TicTacToeBoard::on_numberButton_pressed()
{
    playerMenuWindow->show();
}

void TicTacToeBoard::on_characterButton_pressed()
{
    userRequestWindow->show();
}

bool TicTacToeBoard::getTicTacToeResult()
{
    if(isBoardFull() && !checkWin())
    {
        emit sendWinner(" ");
        disableBoard();
        resultWindow->show();
    }
    else if(checkWin())
    {
        if(currentPlayer % 2 == 0)
            emit sendWinner(secondUserCharacter);
        else
            emit sendWinner(userCharacter);
        disableBoard();
        resultWindow->show();
    }
    else
        return false;
    return true;
}


bool TicTacToeBoard::checkWin()
{
    for (int row = 0; row < 3; row++)
        if(board[row][0] == board[row][1] && board[row][1] == board[row][2] &&
          board[row][0] != "_" && board[row][1] != "_" && board[row][2] != "_")
            return true;

    for (int col = 0; col < 3; col++)
        if(board[0][col] == board[1][col] && board[1][col] == board[2][col] &&
                board[0][col] != "_" && board[1][col] != "_" && board[2][col] != "_")
            return true;

    if((board[0][0] == board[1][1] && board[1][1] == board[2][2] &&
        board[0][0] != "_" && board[1][1] != "_" && board[2][2] != "_") ||

       (board[0][2] == board[1][1] && board[1][1] == board[2][0] &&
            board[0][2] != "_" && board[1][1] != "_" && board[2][0] != "_"))
        return true;

    return false;
}


bool TicTacToeBoard::isBoardFull()
{
   for(int i = 0; i < 3; i++)
   {
       for(int j = 0; j < 3; j++)
       if(board[i][j] == "_")
           return false;
   }
   return true;
}


void TicTacToeBoard::getPlayerCharacter(QString message)
{
    userCharacter = message;
    isCharButtonPressed = true;
    secondUserCharacter = (userCharacter.compare("X"))? "X": "O";

    if(isCharButtonPressed && isNumButtonPressed)
        enableBoard();
}


void TicTacToeBoard::getPlayerNumber(int num)
{
    playerNumber = num;
    isNumButtonPressed = true;

    if(isCharButtonPressed && isNumButtonPressed)
        enableBoard();
}


int TicTacToeBoard::getMoveValue()
{
    for (int row = 0; row < 3; row++)
    {
        if(board[row][0] == board[row][1] && board[row][1] == board[row][2] &&
                board[row][0] != "_" && board[row][1] != "_" && board[row][2] != "_")
        {
            if(board[row][0] == secondUserCharacter)
                return 10;
            else
                return -10;
        }
    }

    for (int col = 0; col < 3; col++)
    {
        if(board[0][col] == board[1][col] && board[1][col] == board[2][col] &&
                board[0][col] != "_" && board[1][col] != "_" && board[2][col] != "_")
        {
            if(board[0][col] == secondUserCharacter)
                return 10;
            else
                return -10;
        }
    }

    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] &&
            board[0][0] != "_" && board[1][1] != "_" && board[2][2] != "_")
    {
       if(board[0][0] == secondUserCharacter)
            return 10;
        else
            return -10;
    }

    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] &&
        board[0][2] != "_" && board[1][1] != "_" && board[2][0] != "_")
    {
        if(board[0][2] == secondUserCharacter)
            return 10;
        else
            return -10;
    }
    return 0;
}


int TicTacToeBoard::minimax(int depth, bool isMax)
{
    int score = getMoveValue();

    if(score == 10)
        return score;

    if(score == -10)
        return score;

    if(isBoardFull())
        return 0;

    if(isMax)
    {
        int best = -1000;
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(board[i][j] == "_")
                {
                    board[i][j] = secondUserCharacter;
                    best = getMax(best, minimax(depth + 1, !isMax));

                    board[i][j] = "_";
                }
            }
        }
        return best;
    }
    else
    {
        int best = 1000;
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(board[i][j] == "_")
                {
                    board[i][j] = secondUserCharacter;
                    best = getMin(best, minimax(depth + 1, !isMax));

                    board[i][j] = "_";
                }
            }
        }
        return best;
    }
}


int TicTacToeBoard::findBestMove()
{
    int bestValue = -1000;
    int row = 0;
    int col = 0;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] == "_")
            {
                int moveValue = minimax(0, false);

                if(moveValue > bestValue)
                {
                    bestValue = moveValue;
                    row = i;
                    col = j;
                    board[i][j] = secondUserCharacter;
                }
            }
        }
    }
    return 3 * row + col;
}


void TicTacToeBoard::computerMove()
{
    switch(findBestMove())
    {
    case 0: ui->pushButton1->setText(secondUserCharacter);
        break;
    case 1: ui->pushButton2->setText(secondUserCharacter);
        break;
    case 2: ui->pushButton3->setText(secondUserCharacter);
        break;
    case 3: ui->pushButton4->setText(secondUserCharacter);
        break;
    case 4: ui->pushButton5->setText(secondUserCharacter);
        break;
    case 5: ui->pushButton6->setText(secondUserCharacter);
        break;
    case 6: ui->pushButton7->setText(secondUserCharacter);
        break;
    case 7: ui->pushButton8->setText(secondUserCharacter);
        break;
    case 8: ui->pushButton9->setText(secondUserCharacter);
    }

    currentPlayer++;

    getTicTacToeResult();
}


void TicTacToeBoard::enableBoard()
{
    ui->numberButton->setEnabled(false);
    ui->characterButton->setEnabled(false);

    ui->pushButton1->setEnabled(true);
    ui->pushButton2->setEnabled(true);
    ui->pushButton3->setEnabled(true);
    ui->pushButton4->setEnabled(true);
    ui->pushButton5->setEnabled(true);
    ui->pushButton6->setEnabled(true);
    ui->pushButton7->setEnabled(true);
    ui->pushButton8->setEnabled(true);
    ui->pushButton9->setEnabled(true);

    timer->start(1000);
}


void TicTacToeBoard::disableBoard()
{
    timer->stop();
    emit sendEstimatedTime(time.toString("mm : ss"));

    ui->pushButton1->setEnabled(false);
    ui->pushButton2->setEnabled(false);
    ui->pushButton3->setEnabled(false);
    ui->pushButton4->setEnabled(false);
    ui->pushButton5->setEnabled(false);
    ui->pushButton6->setEnabled(false);
    ui->pushButton7->setEnabled(false);
    ui->pushButton8->setEnabled(false);
    ui->pushButton9->setEnabled(false);
}


void TicTacToeBoard::setBoardColor()
{
    ui->pushButton1->setStyleSheet("background-color: rgb(218, 218, 218);");
    ui->pushButton2->setStyleSheet("background-color: rgb(218, 218, 218);");
    ui->pushButton3->setStyleSheet("background-color: rgb(218, 218, 218);");
    ui->pushButton4->setStyleSheet("background-color: rgb(218, 218, 218);");
    ui->pushButton5->setStyleSheet("background-color: rgb(218, 218, 218);");
    ui->pushButton6->setStyleSheet("background-color: rgb(218, 218, 218);");
    ui->pushButton7->setStyleSheet("background-color: rgb(218, 218, 218);");
    ui->pushButton8->setStyleSheet("background-color: rgb(218, 218, 218);");
    ui->pushButton9->setStyleSheet("background-color: rgb(218, 218, 218);");
}


void TicTacToeBoard::printTime()
{
    QString timeText = time.toString("mm : ss");
    ui->timeLabel->setText("Time: " + timeText);
    ui->timeLabel->setAlignment(Qt::AlignLeft);
    ui->timeLabel->setStyleSheet("font: 12pt \"MS Shell Dlg 2\"");
    time = time.addSecs(1);
}


int TicTacToeBoard::getMax(int a, int b)
{
    return (a > b)? a: b;
}


int TicTacToeBoard::getMin(int a, int b)
{
    return (a < b)? a: b;
}


TicTacToeBoard::~TicTacToeBoard()
{
    delete ui;
}
