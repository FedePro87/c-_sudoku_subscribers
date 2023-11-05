#ifndef CUSTOM_UTILS
#define CUSTOM_UTILS

#include <iostream>
#include "Cell.h"

class Utils {

    public:

        static void iterateGrid( Cell *grid[9][9] ){

            for (int i = 0; i < 9; i++) {
 
                for (int j = 0; j < 9; j++) {
                    std::cout << "Il valore nella riga " << i << " colonna " << j << " è " << grid[i][j]->value << std::endl;
                }

            }
        }

};

#endif