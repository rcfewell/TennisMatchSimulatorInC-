//Tennis Match Simulator
//Written in c++
//structure created by Dr. Kooshesh and implemented by Riley Fewell

#ifndef _PointScore_hpp
#define _PointScore_hpp

/** The simplest extension of Score is PointScore where one of the two
 * players scores one point.  This rule has been implemented by
 * method, "haveAWinner".
 */

#include "Score.hpp"
#include "Player.hpp"

class PointScore: public Score {

public: 
  PointScore( Player *p1, Player *p2 );
  bool haveAWinner();
  void print();
};

#endif
