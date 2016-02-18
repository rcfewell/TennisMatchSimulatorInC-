//Tennis Match Simulator
//Written in c++
//structure created by Dr. Kooshesh and implemented by Riley Fewell

#include "TieBreaker.hpp"
#include "TieBreakerScore.hpp"
#include "PointScore.hpp"
#include "Game.hpp"

TieBreaker::TieBreaker( Player *p1, Player *p2 ): Competition( p1, p2 ) {}
Score *TieBreaker::play( Player *p ) 
{
	//switches player if necessary
	bool switchPlayer = false;

	//create a tiebreaker instance 
	TieBreakerScore *s = new TieBreakerScore(player1(),player2());

	// serve a point get the winner of the point
	s->addScore(reinterpret_cast<PointScore *>(p->serveAPoint())->getWinner());
	// switch players
	p = p->otherPlayer(p);

	// check for a winner 
	while (!s->haveAWinner())
	{
		// if no winner, proceed with the game
		s->addScore(reinterpret_cast<PointScore *>(p->serveAPoint())->getWinner());
		// and switch when necessary
		if (switchPlayer)
			p = p->otherPlayer(p); 
		switchPlayer = !switchPlayer;
	}

	return s;
}
