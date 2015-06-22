#ifndef HUMANPLAYER_H
#define	HUMANPLAYER_H

#include "Player.h"
#include "PlayedCards.h"


class HumanPlayer : public Player {
public:
	HumanPlayer(bool isPlayerHuman, int playerNumber);
	virtual ~HumanPlayer();
	virtual void HumanPlayer::performMove(PlayedCards& playedCards, Player& player, Card* card, std::string typeOfAction);
	virtual void playCard(PlayedCards&, Player&, Card* card);
	virtual void discardCard(PlayedCards&, Player&, Card* card);
protected:
	
};

#endif	/* HUMANPLAYER_H */

