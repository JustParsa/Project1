/*
* File:   Player.h
* Author: User
*
* Created on June 8, 2012, 10:16 AM
*/

#ifndef PLAYER_H
#define	PLAYER_H

#include <vector>
//#include <deque>
#include "Card.h"

class Player {
public:
	Player(bool, int);
	virtual ~Player();
	void addCard(Card*);
	void newRound();
	void sumTotalPoints();
	//std::vector<Card> getLegalPlays(Table& table) const;
	std::vector<Card*> getHand() const;
	std::vector<Card*> getDiscardedCards() const;
	bool isPlayerHuman() const;
	int getPoints() const;
	int getTotalPoints() const;
	//int getIndex() const;
	//Action performMove(Table& table, Action action);
	void replaceHumanPlayWithComputerPlay();

	friend class HumanPlays;
	friend class ComputerPlays;
private:
	void removeCard(Card* card);
	void addPoints(Card* card);
	void pushDiscardedDeck(Card* card);
	bool hasCard(Card* card) const;
	//bool isCardValid(Table& table, Card card) const;
	std::vector<Card*> hand_; //a list of cards available
	std::vector<Card*> discardedCards_; //a list of discarded cards
	bool isPlayerHuman_; //true if the player is human. False otherwise.
	int points_; //number of points obtained from current round
	int totalPoints_; //number of points obtained before current round
	int playerNumber_;
	//int index; //index of current player
	//Plays* plays; //logic behind the human player to decide whether the given action is valid
};

#endif	/* PLAYER_H */

