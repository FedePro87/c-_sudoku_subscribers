#include "Cell.h"
#include "NumberBroadcaster.h"
#include "types/Subscribers.h"

//SUBSCRIBERS
Subscribers NumberBroadcaster::boxSubscribers(){
    static std::unordered_map<int, std::vector<Cell*>> boxSubscribers;
    return boxSubscribers;
}

Subscribers NumberBroadcaster::rowSubscribers(){
    static std::unordered_map<int, std::vector<Cell*>> rowSubscribers;
    return rowSubscribers;
}

Subscribers NumberBroadcaster::columnSubscribers(){
    static std::unordered_map<int, std::vector<Cell*>> columnSubscribers;
    return columnSubscribers;
}


//How cell subscribe
void NumberBroadcaster::subscribeBox( int boxNum, Cell *cellPtr ){

    NumberBroadcaster::boxSubscribers()[boxNum].push_back(cellPtr);

}

void NumberBroadcaster::subscribeRow( int rowNum, Cell *cellPtr ){

    NumberBroadcaster::rowSubscribers()[rowNum].push_back(cellPtr);

}

void NumberBroadcaster::subscribeColumn( int columnNum, Cell *cellPtr ){

    NumberBroadcaster::columnSubscribers()[columnNum].push_back(cellPtr);

}


//Notifiers
void NumberBroadcaster::notify( std::vector<Cell*> subscribers, int value ){

    for(Cell *cell : subscribers) {

        cell->updateCanPlace(value);
        
    }

}

void NumberBroadcaster::broadcast( int boxNum, int rowNum, int columnNum, int value ){

    NumberBroadcaster::notifyBox( boxNum, value);
    NumberBroadcaster::notifyRow( rowNum, value );
    NumberBroadcaster::notifyColumn( columnNum, value );

}

void NumberBroadcaster::notifyBox( int boxNum, int value ){

    auto it = NumberBroadcaster::boxSubscribers().find(boxNum);
    std::vector<Cell*> boxSubscribers = it->second;
    NumberBroadcaster::notify( boxSubscribers, value );

}

void NumberBroadcaster::notifyRow( int rowNum, int value ){

    auto it = NumberBroadcaster::rowSubscribers().find(rowNum);
    std::vector<Cell*> rowSubscribers = it->second;
    NumberBroadcaster::notify( rowSubscribers, value );

}

void NumberBroadcaster::notifyColumn( int columnNum, int value ){

    auto it = NumberBroadcaster::columnSubscribers().find(columnNum);
    std::vector<Cell*> columnSubscribers = it->second;
    NumberBroadcaster::notify( columnSubscribers, value );

}

void NumberBroadcaster::printSubscribed(){

    for (auto box : NumberBroadcaster::boxSubscribers()){
        
        std::cout << "Nel box con indice " << box.first << " sono presenti le celle con valore : ";

        for(Cell *cell : box.second) {
        
            std::cout << cell->getValue() << " , ";
        
        }

        std::cout << std::endl;

    }

}