#ifndef GAME
#define GAME

#include<QDebug>

class Mychess
{
public:
    explicit Mychess();
    ~Mychess();
    int getchess(int i, int j) const;
    void setchess_0(int i, int j);
    void setchess_1(int i, int j);
    void setchess_2(int i, int j);
    void again();
    int get_x() const;
    int get_y() const;
    void set_x(int x1);
    void set_y(int y1);

private:
    int chess[15][15];
    static int x;
    static int y;
};

#endif // GAME

