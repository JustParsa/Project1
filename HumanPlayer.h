#ifndef HUMANPLAYER_H
#define	HUMANPLAYER_H

#include "Player.h"
#include "PlayedCards.h"

class Player;
class HumanPlayer : public Player {
public:
	HumanPlayer(bool isPlayerHuman, int playerNumber);
	virtual ~HumanPlayer();
	virtual bool performMove(PlayedCards&, Card*, std::string);
	virtual bool playCard(PlayedCards&, Card* card);
	virtual bool discardCard(PlayedCards&, Card* card);
protected:
	
};

#endif	/* HUMANPLAYER_H */

