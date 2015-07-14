#ifndef PLAYER_H
#define	PLAYER_H

#include <vector>
#include <iostream>
#include <string>
#include "Card.h"
#include "PlayedCards.h"
//#include "HumanPlayer.h"
class HumanPlayer;
class Player {
public:
	
	Player(bool, int);
	Player(Player &p);
	virtual ~Player();
	void addCard(Card*);
	void newRound();
	void sumTotalPoints();
	std::vector<Card*> getLegalPlays(PlayedCards& playedCards);
	std::vector<Card*> getHand();
	std::vector<Card*> getDiscardedCards() const;
	bool isPlayerHuman() const;
	int getPoints() const;
	int getTotalPoints() const;
	void removeCard(Card* card);
	void addPoints(Card* card);
	int playerNumber();
	void pushDiscardedDeck(Card* card);
	bool hasCard(Card* card) const;
	void replaceHumanPlayWithComputerPlay();
	virtual bool performMove(PlayedCards&, Card*, std::string) = 0;
	void printAction(Card*, std::string);
private:

	//bool isCardValid(Table& table, Card card) const;
	std::vector<Card*> hand_;
	std::vector<Card*> discardedCards_;
	bool isPlayerHuman_;
	int points_;
	int totalPoints_;
	int playerNumber_;
};

#endif	/* PLAYER_H */

