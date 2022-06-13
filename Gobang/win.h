#ifndef WIN
#define WIN

#include<mychess.h>

class Win
{
public:
    explicit Win();
    bool winning(const Mychess &mc, int x, int y) const;
    bool print(int winning, int i) const;
    int bothwin(const Mychess &mc) const;
    ~Win();

};

#endif // WIN

