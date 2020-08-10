#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
using namespace std;
class player
{
    public:
        player();
        virtual ~player();

        void CallInput();

    protected:
        int x,y;
    private:
};

#endif // PLAYER_H
