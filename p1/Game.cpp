//Tennis Match Simulator
//Written in c++
//structure created by Dr. Kooshesh and implemented by Riley Fewell

#include "Game.hpp"
#include "Score.hpp"
#include "GameScore.hpp"
#include "PointScore.hpp"

Game::Game( Player *p1, Player *p2 ): Competition( p1, p2 ) {} 

Score *Game::play( Player *p ) 
{
	//create a new instance of gameScore
	Score *s = new GameScore( player1(), player2() );

	//check if there should be a winner
    while( !s->haveAWinner() ) 
    {
    	//if not create a new pointScore instance and serve a point
		PointScore *pointScore = reinterpret_cast<PointScore *>( p->serveAPoint() );
		//add point to score and check for winner
		s->addScore( pointScore->getWinner() );
		delete pointScore;
    }

	return s;
}

