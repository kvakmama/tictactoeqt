#include <QApplication>
#include <QPushButton>
#include <QDialog>
#include <QGridLayout>
#include "window.h"
#include "button.h"

int main(int argc, char **argv)
{
 QApplication app (argc, argv);


 QDialog dlg;
 dlg.hide();
 QGridLayout* layout(new QGridLayout);
 dlg.setLayout(layout);
 for(int i = 0; i != 9; ++i)
 {
    QPushButton* pb = new QPushButton("pushme");
    layout->addWidget(pb,i / 3, i % 3);
    QObject::connect(pb, SIGNAL(clicked(bool)), &dlg, SLOT(hide()));
 }

 Window window;
 window.setFixedSize(500, 500);

 Button *button1 = new Button("", &window);
 button1->setGeometry(10, 10, 100, 50);
 //QObject::connect(button1,SIGNAL(clicked(bool)),&dlg,SLOT(show()));
 QObject::connect(button1,SIGNAL(clicked(bool)),&window,SLOT(buttonClicked()));

 Button *button2 = new Button("", &window);
 button2->setGeometry(120, 10, 100, 50);
 QObject::connect(button2,SIGNAL(clicked(bool)),&window,SLOT(buttonClicked()));

 Button *button3 = new Button("", &window);
 button3->setGeometry(230, 10, 100, 50);
 QObject::connect(button3,SIGNAL(clicked(bool)),&window,SLOT(buttonClicked()));

 Button *button4 = new Button("", &window);
 button4->setGeometry(10, 70, 100, 50);
 QObject::connect(button4,SIGNAL(clicked(bool)),&window,SLOT(buttonClicked()));

 Button *button5 = new Button("", &window);
 button5->setGeometry(120, 70, 100, 50);
 QObject::connect(button5,SIGNAL(clicked(bool)),&window,SLOT(buttonClicked()));

 Button *button6 = new Button("", &window);
 button6->setGeometry(230, 70, 100, 50);
 QObject::connect(button6,SIGNAL(clicked(bool)),&window,SLOT(buttonClicked()));

 Button *button7 = new Button("", &window);
 button7->setGeometry(10, 130, 100, 50);
 QObject::connect(button7,SIGNAL(clicked(bool)),&window,SLOT(buttonClicked()));

 Button *button8 = new Button("", &window);
 button8->setGeometry(120, 130, 100, 50);
 QObject::connect(button8,SIGNAL(clicked(bool)),&window,SLOT(buttonClicked()));

 Button *button9 = new Button("", &window);
 button9->setGeometry(230, 130, 100, 50);
 QObject::connect(button9,SIGNAL(clicked(bool)),&window,SLOT(buttonClicked()));
 QObject::connect(button9,SIGNAL(clicked(bool)),&window,SLOT(GameOver((button1->text()),(button5->text()),(button9->text()))));

 window.show();
 return app.exec();
}
