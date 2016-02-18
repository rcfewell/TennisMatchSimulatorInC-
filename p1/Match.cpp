//Tennis Match Simulator
//Written in c++
//structure created by Dr. Kooshesh and implemented by Riley Fewell

#include "Match.hpp"
#include "MatchScore.hpp"
#include "Set.hpp"
 using namespace std;

Match::Match( Player *p1, Player *p2 ): Competition( p1, p2 ) {}

Score *Match::play( Player *p ) {

	MatchScore *s = new MatchScore( player1(), player2() );

	while( !s->haveAWinner() )
	{
		Set *set = new Set( player1(), player2() );

		Score *setScore = set->play( p ); 

		s->addScore( setScore );

		delete set;

		p = p->otherPlayer( p );
	}
    return s;
}
