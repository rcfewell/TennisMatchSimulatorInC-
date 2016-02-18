//Tennis Match Simulator
//Written in c++
//structure created by Dr. Kooshesh and implemented by Riley Fewell

#ifndef _Competition_hpp
#define _Competition_hpp

#include "Player.hpp"

/** Competition is the abstract notion of a "competitive activity"
 * between two players.  It is assumed that this type of activity
 * results in a score that will be reported by an instance of class,
 * "Score".  
 */

class Competition {

public: 
    Competition( Player *player1, Player *player2 );

    Player *player1(); 
    Player *player2();

    virtual Score *play( Player *p ) = 0;

private: 
    Player *p1, *p2;
};
 
#endif
