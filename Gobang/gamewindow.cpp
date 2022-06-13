#include "gamewindow.h"
#include "ui_gamewindow.h"

int flag = 0;       //黑白棋的标记（奇偶性）

Gamewindow::Gamewindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gamewindow)
{
    ui->setupUi(this);
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->label->hide();
    wined = new QSound(":/victory.wav",this);

}


void Gamewindow::paintEvent(QPaintEvent *e)
{
    //绘制棋盘
    this->setFixedSize(720,720);
    this->setAutoFillBackground(true);
    QPalette pal_table;
    pal_table.setColor(QPalette::Background, QColor("#1e477d"));
    this->setPalette(pal_table);

    QPainter painter(this);     //画板
    painter.setRenderHint(QPainter::Antialiasing, true);    //优化边界

    QPen pen = painter.pen();    //画笔
    pen.setColor(Qt::white);
    pen.setWidth(1);
    painter.setPen(pen);

    for(int i = 0; i < 15; i++)     //纵横线
    {
        painter.drawLine(31+47*i, 31, 31+47*i, 689);    //纵线
        painter.drawLine(31, 31+47*i, 689, 31+47*i);    //横线
    }

    QBrush brush;       //参考点
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::white);
    painter.setBrush(brush);
    painter.drawEllipse(167, 167, 10, 10);
    painter.drawEllipse(543, 167, 10, 10);
    painter.drawEllipse(167, 543, 10, 10);
    painter.drawEllipse(543, 543, 10, 10);
    painter.drawEllipse(355, 355, 10, 10);

    //绘制棋子
    for(int i = 0; i < 15; i++)
        for(int j = 0; j < 15; j++)
        {

            pen.setColor(Qt::NoPen);
            painter.setPen(pen);
            if(mc.getchess(j,i) == 1)    //黑子,重新覆盖
            {
                brush.setColor(Qt::black);
                painter.setBrush(brush);
                painter.drawEllipse(QPoint(31+47*j, 31+47*i), 18, 18);
            }
            else if(mc.getchess(j,i) == 2)   //白子
            {
                brush.setColor(Qt::white);
                painter.setBrush(brush);
                painter.drawEllipse(QPoint(31+47*j, 31+47*i), 18, 18);
            }
        }
    int w0 = win.bothwin(mc);
    if(win.print(w0, 0))
    {
        wined->play();
        ui->label->setText("和棋！");
        ui->label->show();
        ui->pushButton->show();
        ui->pushButton_2->show();
    }
    update();
}


void Gamewindow::mousePressEvent(QMouseEvent *e)        //优化点击范围
{
    if(Qt::LeftButton == e->button())
    {
        int x = e->x();
        int y = e->y();

        for(int i = 0; i < 15; i++)
        {
            int exit = 0;
            for(int j = 0; j < 15; j++)
            {
                if((31+47*j-12 <= x) && (31+47*j+12 >= x) && (31+47*i-12 <= y) && (31+47*i+12 >= y) && mc.getchess(j,i) != 1 && mc.getchess(j,i) != 2)
                {
                    x = j;
                    y = i;
                    ++flag;
                    exit = 1;
                    break;
                }
            }
            if(exit == 1)
                break;
        }

        if(flag > 0)
        {
            mc.set_x(x);
            mc.set_y(y);
            if(flag%2 == 1)
            {
                mc.setchess_1(x, y);
                bool w1 = win.winning(mc, x, y);
                if(win.print(w1, 1))
                {
                    wined->play();
                    ui->label->setText("黑棋胜！");
                    ui->label->show();
                    ui->pushButton->show();
                    ui->pushButton_2->show();
                }
            }
            else
            {
                mc.setchess_2(x, y);
                bool w2 = win.winning(mc, x, y);
                if(win.print(w2, 2))
                {
                    wined->play();
                    ui->label->setText("白棋胜！");
                    ui->label->show();
                    ui->pushButton->show();
                    ui->pushButton_2->show();
                }
            }
        }
    }
}

void Gamewindow::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu *menu = new QMenu(this);
    QAction *my_reply = new QAction(this);
    QAction *my_newgame = new QAction(this);
    QAction *my_exitgame = new QAction(this);

    connect(my_reply,SIGNAL(triggered()),this,SLOT(replay()));
    connect(my_newgame,SIGNAL(triggered()),this,SLOT(newgame()));
    connect(my_exitgame,SIGNAL(triggered()),this,SLOT(exitgame()));

    my_reply->setText("悔棋");
    my_newgame->setText("重玩");
    my_exitgame->setText("退出");

    menu->addAction(my_reply);
    menu->addSeparator();//添加分割线
    menu->addAction(my_newgame);
    menu->addSeparator();//添加分割线
    menu->addAction(my_exitgame);

    menu->exec(QCursor::pos());
}

Gamewindow::~Gamewindow()
{
    delete ui;
    delete wined;
}

void Gamewindow::on_pushButton_clicked()        //再来一局
{
    ui->label->hide();
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    mc.again();
}

void Gamewindow::on_pushButton_2_clicked()      //退出
{
    qApp->quit();       //qApp是全局指针
    qDebug()<<"程序正常退出"<<endl;
}

void Gamewindow::replay()
{
    mc.setchess_0(mc.get_x(), mc.get_y());
    flag++;
    qDebug()<<"悔棋成功"<<endl;
}

void Gamewindow::newgame()
{
    mc.again();
    qDebug()<<"重玩成功"<<endl;
}

void Gamewindow::exitgame()
{
    qApp->quit();       //qApp是全局指针
    qDebug()<<"程序正常退出"<<endl;
}
