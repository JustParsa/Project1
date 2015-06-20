#ifndef COMPUTERPLAYER_H
#define	COMPUTERPLAYER_H

#include "HumanPlayer.h"
#include "Player.h"
#include <deque>
#include <string>

class ComputerPlayer : public Player{
public:
	ComputerPlayer();
	virtual ~ComputerPlayer();
	void performMove(PlayedCards& playedCards, Player& player, Card* card, std::string typeOfAction);
	void playCard(PlayedCards&, Player&, Card*);
	void discardCard(PlayedCards&, Player&, Card*);
protected:

};


#endif	/* COMPUTERPLAYER_H */

