#ifndef CELL
#define CELL

#include <unordered_map>

class Cell {

    private :

        std::unordered_map<int, bool> canPlace;

    public :

        //Box a cui appartiene
        int boxNum;

        //Riga a cui appartiene
        int rowNum;

        //Colonna a cui appartiene
        int columnNum;

        //Valore nella cella
        int value;
    
        Cell( int boxNum, int rowNum, int columnNum, int value );


        void updateCanPlace( int value );

};

#endif