//Tennis Match Simulator
//Written in c++
//structure created by Dr. Kooshesh and implemented by Riley Fewell

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "SetScore.hpp"
using namespace std;


SetScore::SetScore( Player *p1, Player *p2 ): Score(p1, p2), tieScore(0) {}
  
bool SetScore::haveAWinner()
{ 
    // winner of a set when a player reaches 6 and is ahead by 2 or more sets
	return ( (player1Score() >= 6 || player2Score() >= 6) && ( abs( player1Score() - player2Score() ) >= 2 ) );  
}
bool SetScore::shouldPlayATieBreaker()
{
    // tie when both have reached 6 
	return player1Score() == 6 && player2Score() == 6 ;
}

void SetScore::addTieScore( TieBreakerScore *score ) 
{
    addScore( score->getWinner() );
    this->tieScore = score;
}

void SetScore::print() {

    // prints out the set scores 
    cout << setw(13) << player1Score () << setw(15) << player2Score ();

    if( tieScore != NULL )
      tieScore->print();
}
