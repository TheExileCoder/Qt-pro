#include<mychess.h>

int Mychess::x = 0;
int Mychess::y = 0;

Mychess::Mychess()
{
    for(int i = 0; i < 15; i++)
        for(int j = 0; j < 15; j++)
            chess[i][j] = 0;
}

int Mychess::getchess(int i, int j) const
{
    return chess[i][j];
}

void Mychess::setchess_0(int i, int j)      //清空
{
    chess[i][j] = 0;
}

void Mychess::setchess_1(int i, int j)      //黑子
{
    chess[i][j] = 1;
}

void Mychess::setchess_2(int i, int j)      //白子
{
    chess[i][j] = 2;
}

void Mychess::again()
{
    for(int i = 0; i < 15; i++)
        for(int j = 0; j < 15; j++)
            chess[i][j] = 0;
}

int Mychess::get_x() const
{
    return x;
}

int Mychess::get_y() const
{
    return y;
}

void Mychess::set_x(int x1)
{
    x = x1;
}

void Mychess::set_y(int y1)
{
    y = y1;
}

Mychess::~Mychess(){}
