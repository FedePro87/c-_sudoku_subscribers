#ifndef NUMBER_BROADCASTER
#define NUMBER_BROADCASTER

#include <iostream>
#include <unordered_map>
#include <vector>

class NumberBroadcaster {

    private :

        static void notify( std::vector<Cell*> subscribed );

    public :

        //SUBSCRIBERS
        typedef std::unordered_map<int, std::vector<Cell*>>& Subscribers;
        static Subscribers boxSubscribers();
        static Subscribers rowSubscribers();
        static Subscribers columnSubscribers();


        //How cell subscribe
        static void subscribeBox( int boxNum, Cell *cellPtr );
        static void subscribeRow( int rowNum, Cell *cellPtr );
        static void subscribeColumn( int columnNum, Cell *cellPtr );


        //Notifiers
        static void notify( std::vector<Cell*> subscribers, int value );
        static void notifyBox( int boxNum, int value );
        static void notifyRow( int rowNum, int value );
        static void notifyColumn( int columnNum, int value );
        

        // static void numberInBox( int boxNum, int value );


        static void printSubscribed();

};

#endif