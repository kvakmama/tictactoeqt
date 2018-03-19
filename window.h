#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

class Window : public QWidget
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = nullptr);

signals:

public slots:
    void buttonClicked();
    void GameOver(QString a,QString b,QString c);
};

#endif // WINDOW_H
//QString a,QString b,QString c
