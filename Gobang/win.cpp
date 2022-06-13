#include<win.h>

Win::Win(){}

int Win::bothwin(const Mychess &mc) const
{
    for(int i = 0; i < 15; i++)
        for(int j = 0; j < 15; j++)
        {
            if(mc.getchess(i, j) == 0)
                return 0;
        }
    return 2;
}

bool Win::winning(const Mychess &mc, int x, int y) const
{
    int i = 1, j = 1;
    int num[4] = {1,1,1,1};
    while((y-i>=0) && mc.getchess(x, y) == mc.getchess(x, y-i))
    {
        num[0]++;
        i++;
    }
    while ((y+j<=14) && mc.getchess(x, y) == mc.getchess(x, y+j))
    {
        num[0]++;
        j++;
    }
    if(num[0]>4)        //纵向
        return true;
    i = 1;
    j = 1;
    while((x-i>=0) && mc.getchess(x, y) == mc.getchess(x-i, y))
    {
        num[1]++;
        i++;
    }
    while((x+j<=14) && mc.getchess(x, y) == mc.getchess(x+j, y))
    {
        num[1]++;
        j++;
    }
    if(num[1]>4)        //横向
        return true;
    i = 1;
    j = 1;
    while ((x-i>=0) && (y-i>=0) && mc.getchess(x, y) == mc.getchess(x-i, y-i))
    {
        num[2]++;
        i++;
    }
    while((x+j<=14) && (y+j<=14) && mc.getchess(x, y) == mc.getchess(x+j, y+j))
    {
        num[2]++;
        j++;
    }
    if(num[2]>4)        //主对角线
        return true;
    i = 1;
    j = 1;
    while ((x+i<=14) && (y-i>=0) && mc.getchess(x, y) == mc.getchess(x+i, y-i))
    {
        num[3]++;
        i++;
    }
    while((x-j>=0) && (y+j<=14) && mc.getchess(x, y) == mc.getchess(x-j, y+j))
    {
        num[3]++;
        j++;
    }
    if(num[3]>4)        //副对角线
        return true;

    return false;
}

bool Win::print(int winning, int i) const
{
    if(1 == i && winning == true)       //黑棋胜利
        return true;
    else if(2 == i && winning == true)      //白棋胜利
        return true;
    else if(0 == i && winning == 2)     //平局
        return true;
    return false;

}

Win::~Win(){}
