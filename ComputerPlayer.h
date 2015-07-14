
#ifndef COMPUTERPLAYER_H
#define	COMPUTERPLAYER_H

#include "HumanPlayer.h"
#include "Player.h"
#include <string>

class ComputerPlayer : public Player{
public:
	ComputerPlayer(bool,int);
	ComputerPlayer(Player& player);
	virtual ~ComputerPlayer();
	virtual bool ComputerPlayer::performMove(PlayedCards& playedCards, Card* card, std::string typeOfAction);
	virtual bool playCard(PlayedCards&, Card* card);
	virtual bool discardCard(PlayedCards&, Card* card);
protected:

};


#endif	*//* COMPUTERPLAYER_H */
