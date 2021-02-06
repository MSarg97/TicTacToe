#ifndef PLAYERMENU_H
#define PLAYERMENU_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>

namespace Ui {
class PlayerMenu;
}

class PlayerMenu : public QWidget
{
    Q_OBJECT

public:
    explicit PlayerMenu(QWidget *parent = nullptr);
    ~PlayerMenu();

signals:
    void sendNumber(int);

public slots:
    void onePlayerButtonClicked();
    void aboutOnePlayerClicked();
    void twoPlayerButtonClicked();
    void aboutTwoPlayersClicked();

private:
    Ui::PlayerMenu *ui;
    QVBoxLayout *verticalLayout;
    QPushButton *firstPushButton;
    QPushButton *aboutOnePlayer;
    QPushButton *secondPushButton;
    QPushButton *aboutTwoPlayers;
    QLabel *label;
};

#endif // PLAYERMENU_H
