#ifndef CUSTOM_UTILS
#define CUSTOM_UTILS

#include <iostream>
#include "Cell.h"

class Utils {

    public:

        static void drawGrid( Cell *grid[9][9] ){

            int placeBorderCounter = 0;

            for (int i = 0; i < 9; i++) {

                std::cout << " | ";
 
                for (int j = 0; j < 9; j++) {

                    std::cout << grid[i][j]->getValue();
                    placeBorderCounter++;

                    if(placeBorderCounter == 3){
                        std::cout << " | ";
                        placeBorderCounter = 0;
                    }

                }

                std::cout << std::endl;

            }
        }

        static void iterateHashmap( PossibilityHashmap possibilityHashmap ){

            for (auto const& x : possibilityHashmap){

                std::cout << x.first << ':' << x.second << std::endl;

            }

        }

};

#endif