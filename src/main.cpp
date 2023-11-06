#include "Cell.h"
#include "NumberBroadcaster.h"
#include "Utils.cpp"

Cell *grid[9][9] = {
	{ new Cell(0,0,0,0), new Cell(0,0,1,0), new Cell(0,0,2,0), new Cell(1,0,3,4), new Cell(1,0,4,0), new Cell(1,0,5,0), new Cell(2,0,6,0), new Cell(2,0,7,0), new Cell(2,0,8,0) },
	{ new Cell(0,1,0,5), new Cell(0,1,1,8), new Cell(0,1,2,0), new Cell(1,1,3,0), new Cell(1,1,4,6), new Cell(1,1,5,0), new Cell(2,1,6,0), new Cell(2,1,7,4), new Cell(2,1,8,9) },
	{ new Cell(0,2,0,0), new Cell(0,2,1,7), new Cell(0,2,2,0), new Cell(1,2,3,0), new Cell(1,2,4,2), new Cell(1,2,5,0), new Cell(2,2,6,0), new Cell(2,2,7,0), new Cell(2,2,8,1) },
	{ new Cell(3,3,0,0), new Cell(3,3,1,0), new Cell(3,3,2,0), new Cell(4,3,3,0), new Cell(4,3,4,0), new Cell(4,3,5,0), new Cell(5,3,6,4), new Cell(5,3,7,7), new Cell(5,3,8,0) },
	{ new Cell(3,4,0,0), new Cell(3,4,1,9), new Cell(3,4,2,0), new Cell(4,4,3,1), new Cell(4,4,4,5), new Cell(4,4,5,0), new Cell(5,4,6,3), new Cell(5,4,7,8), new Cell(5,4,8,2) },
	{ new Cell(3,5,0,0), new Cell(3,5,1,0), new Cell(3,5,2,7), new Cell(4,5,3,0), new Cell(4,5,4,0), new Cell(4,5,5,4), new Cell(5,5,6,0), new Cell(5,5,7,1), new Cell(5,5,8,6) },
	{ new Cell(6,6,0,0), new Cell(6,6,1,4), new Cell(6,6,2,6), new Cell(7,6,3,0), new Cell(7,6,4,3), new Cell(7,6,5,0), new Cell(8,6,6,0), new Cell(8,6,7,2), new Cell(8,6,8,0) },
	{ new Cell(6,7,0,0), new Cell(6,7,1,0), new Cell(6,7,2,5), new Cell(7,7,3,0), new Cell(7,7,4,0), new Cell(7,7,5,0), new Cell(8,7,6,8), new Cell(8,7,7,0), new Cell(8,7,8,0) },
	{ new Cell(6,8,0,0), new Cell(6,8,1,2), new Cell(6,8,2,0), new Cell(7,8,3,5), new Cell(7,8,4,0), new Cell(7,8,5,9), new Cell(8,8,6,0), new Cell(8,8,7,0), new Cell(8,8,8,0) }
};

void traverseGrid( Cell *grid[9][9] ){

	for (int row = 0; row < 9; row++) {
 
        for (int column = 0; column < 9; column++) {

			Cell cell = *grid[row][column];

			//Check if cell has 0.
			if(cell.getValue() == 0){

				//If has 0, check if has only canPlace number possibility
				if(cell.getCanPlace().size() == 1){
					int placingValue = cell.getCanPlace().begin()->first;
					cell.setValue(placingValue);
					NumberBroadcaster::broadcast( cell.getBoxNum(), row, column, placingValue );
				}

			}
			//Else, broadcast this value.
			else {
				int placingValue = cell.getValue();
				NumberBroadcaster::broadcast( cell.getBoxNum(), row, column, placingValue );
			}
            
        }

    }

}

int main(){

	Utils::drawGrid( grid );

    std::cout << std::endl;
    std::cout << std::endl;
	traverseGrid( grid );

	Utils::drawGrid( grid );

	return 0;

}