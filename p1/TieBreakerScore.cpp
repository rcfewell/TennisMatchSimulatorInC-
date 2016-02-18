//Tennis Match Simulator
//Written in c++
//structure created by Dr. Kooshesh and implemented by Riley Fewell

#include "TieBreakerScore.hpp"
#include <cstdlib>
#include <iomanip>
#include <iostream>

using namespace std;

TieBreakerScore::TieBreakerScore( Player *p1, Player *p2 ): Score(p1, p2) {}

bool TieBreakerScore::haveAWinner()
{
	//Winner of a tie when a player has more than 7 points and is ahead by 2 games
	return ( ( player1Score() >= 7 || player2Score() >= 7) && ( abs( player1Score() - player2Score() >= 2) ) );
}

void TieBreakerScore::print()
{
	//prints the tie breaker in format EX: (tie breaker 9-7)
	cout << setw(18) << "(tie breaker " << player1Score() << "-" << player2Score() << ")";
}