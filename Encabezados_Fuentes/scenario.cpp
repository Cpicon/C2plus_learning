#include "scenario.h"
#include "player.h"
scenario::scenario(int row, int column)
{
    //ctor
    //Row = row;
    //Column= column;
};

void scenario::draw(int row,int column)
{
    cout<<row<<endl;
    for(int n_row=0; n_row<row; n_row = n_row+1)
        {
            for(int n_colum=0; n_colum<column; n_colum= n_colum+1)
            {
                cout<<0;
            }
            cout<<endl;
        }
};

