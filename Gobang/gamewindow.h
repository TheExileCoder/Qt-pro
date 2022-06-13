#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include<mychess.h>
#include<QPainter>
#include<QDebug>
#include<QMouseEvent>
#include<win.h>
#include<QContextMenuEvent>
#include<qmenu.h>
#include<qaction.h>
#include<QCursor>
#include<qsound.h>

namespace Ui {
class gamewindow;
}

class Gamewindow : public QWidget
{
    Q_OBJECT

public:
    explicit Gamewindow(QWidget *parent = 0);
    ~Gamewindow();
    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent *e);

protected:
    void contextMenuEvent(QContextMenuEvent *event);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void replay();      //悔棋
    void newgame();     //重玩
    void exitgame();    //退出

private:
    Ui::gamewindow *ui;
    Mychess mc;
    Win win;
    QSound *wined;
};

#endif // GAMEWINDOW_H
