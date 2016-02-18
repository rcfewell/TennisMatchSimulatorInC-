//Tennis Match Simulator
//Written in c++
//structure created by Dr. Kooshesh and implemented by Riley Fewell

#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include "GameScore.hpp"

GameScore::GameScore( Player *p1, Player *p2 ): Score( p1, p2 ) {}
    
bool GameScore::haveAWinner() 
{	// winner of a game is first player to 4 or more and being ahead by 2 or more points
	return ( p1Score >= 4 || p2Score >= 4 ) && abs( p1Score - p2Score ) >= 2;
}

void GameScore::print() 
{
	//Not used
	std::cout <<  "GameScore...   printing begins" << std::endl;
	std::cout <<  "p1 score = " << player1Score() << "\np2 Score = " << player2Score() << std::endl;
	std::cout <<  "GameScore...   printing ends" << std::endl;
}
