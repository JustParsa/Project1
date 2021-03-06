
#ifndef COMPUTERPLAYER_H
#define	COMPUTERPLAYER_H

#include "Player.h"
#include <string>

class ComputerPlayer : public Player{
public:
	ComputerPlayer(bool,int);
	ComputerPlayer(Player&);
	virtual ~ComputerPlayer();
	virtual bool performMove(PlayedCards&, Card*, std::string);
	virtual bool playCard(PlayedCards&, Card* card);
	virtual bool discardCard(PlayedCards&, Card* card);
protected:

};


#endif	/* COMPUTERPLAYER_H */

