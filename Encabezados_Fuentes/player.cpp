#include "player.h"

player::player()
{
    //ctor
    x= 0;
    y= 0;
};

void player::CallInput()
{
    char UserInput;
    cin>> UserInput;
    switch(UserInput){
        case 'w':
            y = y+1;
            break;
        case 's':
            y = y-1;
            break;
        case 'a':
            x = x-1;
            break;
        case 'd':
            x = x+1;
            break;
    }
    cout<<"coordenadas : ("<<x<<","<<y<<")"<<endl;
}

player::~player()
{
    //dtor
}
