#include "window.h"
#include <QPushButton>
#include <iostream>
using namespace std;
Window::Window(QWidget *parent) : QWidget(parent)
{

}

int counter = 0;

void Window::buttonClicked()
{
    QPushButton* pb(qobject_cast<QPushButton*>(sender()));
    if (pb)
    {
        counter ++;
        if (counter % 2 == 0)
            pb->setText("O");
        else
            pb->setText("X");
        pb->setEnabled(false);
    }
}

void Window::GameOver(QString a,QString b,QString c)
{
    QPushButton* pb(qobject_cast<QPushButton*>(sender()));
    if (a == b && a == c)
    {
        pb->setText("WIN");
    }
}
