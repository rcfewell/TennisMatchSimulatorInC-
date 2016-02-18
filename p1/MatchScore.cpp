//Tennis Match Simulator
//Written in c++
//structure created by Dr. Kooshesh and implemented by Riley Fewell

#include "MatchScore.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

MatchScore::MatchScore( Player *p1, Player *p2 ): Score( p1, p2 ), setNumber(0) {}
bool MatchScore::haveAWinner()  
{ 
	return (player1Score() == 3 || player2Score() == 3);  
}  
void MatchScore::addScore( Score *score ) 
{
	scores[setNumber] = reinterpret_cast<SetScore *>(score);
	setNumber++;
	score->getWinner() == player1() ? p1Score++ : p2Score++;
}

void MatchScore::print() 
{
	//format the out put to be similar than the working demo given
	// to use
	//EX:   Set No.        Player 1        Player 2
	//         1			   6			  0
	//         2			   6	          0 
	//		   3			   6			  0
	// Player 1 wins the match 3 to 0
	 
	cout << "    Set No.    Player 1        Player 2" << endl;
	for( int i = 0; i < setNumber; i++ )
	{
		cout << setw(7) << i+1;
		scores[i]->print();
		cout << endl;
	}

	if( player1Score() > player2Score () )
		cout << "Player 1 wins the match " << player1Score() << " to " << player2Score() << endl;
	else
		cout << "Player 2 wins the match " << player2Score() << " to " << player1Score() << endl;



}
MatchScore::~MatchScore() 
{
    for( int i = 0; i < setNumber; i++ )
      delete scores[i];
}
