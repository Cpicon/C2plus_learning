#ifndef SCENARIO_H
#define SCENARIO_H
#include "map_cell.h"

class scenario
{
    public:
        const static int Row =2;
        const static int Column = 2;
        map_cell GridMap[Row][Column];
        scenario(int row, int column);
        void draw(int Row, int Column);

    protected:

    private:
};

#endif // SCENARIO_H
