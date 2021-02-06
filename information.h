#ifndef INFORMATION_H
#define INFORMATION_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

namespace Ui {
class Information;
}

class Information : public QWidget
{
    Q_OBJECT

public:
    explicit Information(QWidget *parent = nullptr);
    ~Information();

private slots:
    void okButtonPressed();

private:
    Ui::Information *ui;
    QLabel *label;
    QPushButton *okButton;
    QVBoxLayout *verticalLayout;
};

#endif // INFORMATION_H
