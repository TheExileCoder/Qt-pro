#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //调色板绘制背景
    QPalette pal = this->palette();
    pal.setBrush(QPalette::Background, QBrush(QPixmap(":/welcome.jpg")));
    setPalette(pal);

    gw = new Gamewindow;    //创建子窗口

    //播放背景音乐
    sound = new QSound(":/welcome.wav",this);
    sound->setLoops(-1);
    sound->play();

    qDebug()<<"欢迎界面打开成功"<<endl;
}

Widget::~Widget()
{
    delete ui;
    delete gw;
    delete sound;
}

void Widget::on_pushButton_2_clicked()
{
    qApp->quit();       //qApp是全局指针
    qDebug()<<"程序正常退出"<<endl;
}

void Widget::on_pushButton_clicked()
{
    gw->show();         //显示游戏界面
    this->hide();       //隐藏欢迎界面
    sound->stop();      //停止播放音乐
    qDebug()<<"游戏界面打开成功"<<endl;
}
