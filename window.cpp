#include "window.h"
#include <QPushButton>
#include <iostream>
#include <QGridLayout>
#include <QMessageBox>
#include <QPalette>
using namespace std;
Window::Window(QWidget *parent) : QWidget(parent)
{
    QGridLayout* layout(new QGridLayout);
    setLayout(layout);
    for (int i = 0; i != 3; ++i)
    {
       for (int j = 0; j != 3; ++j)
       {
            QPushButton* pb = new QPushButton;
            pb->setSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::MinimumExpanding);
            layout->addWidget(pb,i,j);
            connect(pb, SIGNAL(clicked(bool)), this, SLOT(buttonClicked()));
            QFont font = pb->font();
            font.setPointSize(33);
            pb->setFont(font);
            mButtons[i][j]=pb;
       }
    }
    UpdateUI();
}

void Window::UpdateUI()
{
    for (int i = 0; i != 3; ++i)
    {
       for (int j = 0; j != 3; ++j)
       {
            QPushButton* pb = mButtons[i][j];
            int state = mGame.get_elem(game::input{i,j});
            QString color;
            if (state == 0)
            {
                pb->setEnabled(true);
                pb->setText("");
                color = "gray";
            }
            else if (state == 1)
            {
                pb->setEnabled(false);
                pb->setText("X");
                color = "cyan";
            }
            else if (state == 2)
            {
                pb->setEnabled(false);
                pb->setText("O");
                color = "magenta";
            }
            pb->setStyleSheet("color:black; background-color:"+color);
       }
    }
}

void Window::buttonClicked()
{
    QPushButton* pb(qobject_cast<QPushButton*>(sender()));
    if (pb)
    {
        for (int i=0; i!=3; ++i)
        {
            for (int j=0; j!=3; ++j)
            {
                if (mButtons[i][j] == pb)
                {
                    game::input inp{i,j};
                    mGame.process_input(inp);
                }
            }
        }
    }
    UpdateUI();
    if (mGame.game_over())
    {
        GameOver();
    }
}

void Window::GameOver()
{
    int winner = mGame.find_winner();
    QString message;
    if (winner == 0)
    {
        message = "Draw";
    }
    else
    {
        message = QString("player %1 won").arg(winner);
    }
    QMessageBox::information(nullptr,"Game Over",message);
    mGame.init();
    UpdateUI();
}
