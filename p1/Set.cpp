//Tennis Match Simulator
//Written in c++
//structure created by Dr. Kooshesh and implemented by Riley Fewell

#include "Set.hpp"
#include "SetScore.hpp"
#include "Game.hpp"
#include "GameScore.hpp"
#include "TieBreaker.hpp"
#include <iostream>

using namespace std;


Set::Set( Player *p1, Player *p2 ): Competition( p1, p2 ) {}

Score *Set::play( Player *p ) 
{
	SetScore *s = new SetScore( player1 (), player2 () ); 
	
	while( !s->haveAWinner() )
	{
		Game *g = new Game( player1(), player2() );// s == score

		Score *gs = g->play(p); //gs == gameScore
		s->addScore(gs->getWinner () );

		delete g;

		p = p->otherPlayer(p);

		TieBreaker* tie = new TieBreaker(player1(),player2());


		if( s->shouldPlayATieBreaker() )
		{
			s->addTieScore( reinterpret_cast<TieBreakerScore *>(tie->play(p)));
			break;
		}

		delete tie;
		delete gs;

	}


    return s;
}

