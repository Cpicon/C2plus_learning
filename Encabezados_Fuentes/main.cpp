#include "player.h"
#include "scenario.h"
#include "map_cell.h"
#include <iostream>


int main()
{
    bool GameOver= false;
    int row,column;
    cout<<"Ingrese el tamaño del mapa"<<endl;
    cout<<"alto :"<<endl;
    cin>>row;
    cout<<"ancho :"<<endl;
    cin>>column;
    scenario map_game(row,column);
    player Hero;
    cout<<"El juego emppieza"<<endl;
    while(GameOver==false){
        Hero.CallInput();
        map_game.draw(row,column);
    }

    cout << "Hello world!" << endl;
    return 0;
}
