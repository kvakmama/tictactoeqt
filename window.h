#ifndef WINDOW_H
#define WINDOW_H
#include <QPushButton>
#include <QWidget>
#include "game.h"
#include "button.h"

class Window : public QWidget
{
    Q_OBJECT
    // storing the current game state
    game mGame;
    // holding the buttons matching the game state
    QPushButton* mButtons[3][3];

    void UpdateUI();
    void GameOver();
public:
    explicit Window(QWidget *parent = nullptr);

public slots:
    void buttonClicked();
};

#endif // WINDOW_H
//QString a,QString b,QString c
