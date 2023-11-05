#include "Cell.h"
#include "NumberBroadcaster.h"

Cell::Cell( int boxNum, int rowNum, int columnNum, int value ){
    this->boxNum = boxNum;
    this->rowNum = rowNum;
    this->columnNum = columnNum;
    this->value = value;

    NumberBroadcaster::subscribeBox( this->boxNum, this );
    NumberBroadcaster::subscribeRow( this->rowNum, this );
    NumberBroadcaster::subscribeColumn( this->columnNum, this );

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

void Cell::updateCanPlace( int value ){

    this->canPlace.erase(value);

}