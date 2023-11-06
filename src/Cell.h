#ifndef CELL
#define CELL

#include <unordered_map>

#include "types/PossibilityHashmap.h"

class Cell {

    private :

        int boxNum;
        int rowNum;
        int columnNum;
        int value;

        PossibilityHashmap canPlace;

    public :
    
        //Constructors
        Cell( int boxNum, int rowNum, int columnNum, int value );

        //Class methods
        void updateCanPlace( int value );

        //GETTERS
        int getValue();
        int getBoxNum();
        PossibilityHashmap getCanPlace();

        //SETTERS
        void setValue( int value );

};

#endif