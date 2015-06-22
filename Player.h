#ifndef PLAYER_H
#define	PLAYER_H

#include <vector>
#include <iostream>
#include <string>
#include "Card.h"
#include "PlayedCards.h"

class Player {
public:
	
	class IllegalMoveException {									//Exception if the Collection is invalid. 
	public:
		IllegalMoveException(std::string);
		~IllegalMoveException() {};
		std::string msg();
	private:
		std::string msg_;
	};
	
	Player(bool, int);
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
	void pushDiscardedDeck(Card* card);
	bool hasCard(Card* card) const;
	//Action performMove(Table& table, Action action);
	void replaceHumanPlayWithComputerPlay();
	virtual void performMove(PlayedCards& playedCards, Player& player, Card* card, std::string typeOfAction) = 0;
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

