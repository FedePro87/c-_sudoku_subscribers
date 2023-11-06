#include "Cell.h"
#include "NumberBroadcaster.h"
#include "Utils.cpp"
#include "types/PossibilityHashmap.h"

Cell::Cell( int boxNum, int rowNum, int columnNum, int value ){
    this->boxNum = boxNum;
    this->rowNum = rowNum;
    this->columnNum = columnNum;
    this->value = value;

    NumberBroadcaster::subscribeBox( this->boxNum, this );
    NumberBroadcaster::subscribeRow( this->rowNum, this );
    NumberBroadcaster::subscribeColumn( this->columnNum, this );

    if(this->value != 0){
        this->canPlace[this->value] = false;
    } else {
        this->canPlace[1] = false;
        this->canPlace[2] = false;
        this->canPlace[3] = false;
        this->canPlace[4] = false;
        this->canPlace[5] = false;
        this->canPlace[6] = false;
        this->canPlace[7] = false;
        this->canPlace[8] = false;
        this->canPlace[9] = false;
    }

}

void Cell::updateCanPlace( int value ){

    this->canPlace.erase(value);

    if(this->canPlace.size() == 1){
		int placingValue = this->canPlace.begin()->first;
		this->value = placingValue;
		NumberBroadcaster::broadcast( this->boxNum, this->rowNum, this->columnNum, placingValue );
	}

}


//GETTERS
int Cell::getValue(){
    return this->value;
}

int Cell::getBoxNum(){
    return this->boxNum;
}

PossibilityHashmap Cell::getCanPlace(){
    return this->canPlace;
}


//Setters
void Cell::setValue( int value ){
    this->value = value;
}