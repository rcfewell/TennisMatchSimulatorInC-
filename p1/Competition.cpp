//Tennis Match Simulator
//Written in c++
//structure created by Dr. Kooshesh and implemented by Riley Fewell

#include "Competition.hpp"
#include "Player.hpp"

Competition::Competition( Player *player1, Player *player2 ): p1( player1 ), p2 ( player2 ) {}

Player *Competition::player1()
{ 
	return p1; 
}

Player *Competition::player2()
{ 
	return p2; 
}
