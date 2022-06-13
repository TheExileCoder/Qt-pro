#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<gamewindow.h>
#include<QSound>
#include<QDebug>
#include<QApplication>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();


private:
    Ui::Widget *ui;
    Gamewindow *gw;
    QSound* sound;
};

#endif // WIDGET_H
