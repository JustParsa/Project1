#ifndef GAME_H
#define	GAME_H

#include "Card.h"
#include "Player.h"
#include "PlayedCards.h"
#include <vector>
#include <deque>

class Game {
public:
	Game(std::vector<bool> humanPlayers, int);		//Initialises the deck, the players, shuffles the deck, distributes the cards
	
	/*
	class NoBuildingFound : public IllegalMoveException{
	public:
		NoBuildingFound(std::string s) : IllegalMoveException(s){};
	};
	class BuildingAlreadyExists : public IllegalMoveException{
	public:
		BuildingAlreadyExists(std::string s) : IllegalMoveException(s){};
	};
	*/
	//virtual ~Game();
	//void next();
	void newRound();
	void initDeck();
	void initPlayerCards();
	int findFirstPlayer();
	void shuffle();
	bool numPointsGreaterThanEighty() const;
	void nextPlayer();
	void playCard(Card *card, string);
	//Action humanDiscardsCard(Card card);
	//Action computerPerformsMove();
	//void humanRageQuit();
	bool isGameOver() const;
	bool isCurrentPlayerHuman() const;
	int addAllPlayerPoints() const;
	void printCards() const;
	void printHumanGameplay();
	void getPlayerCards();
	int getPlayerPoints(int);
	int getPlayerTotalPoints(int);
	int getCurrentPlayer() const;
	Card* getPointerToCard(Card card);
	//std::vector<Card*> getDeck() const;
	//std::deque<Card*> getCardsOnTableOfSuit(Suit suit) const;
	//std::vector<Card*> getCurrentPlayerHand() const;
	//std::vector<Card*> getCurrentPlayerLegalPlays() const;
	std::vector<Card*> getDiscardedCards(int) const;
private:
	Card* cards_[52]; //all cards of the deck
	Player* players_[4]; //players of the game
	//std::vector<Card*> playedCards_;
	PlayedCards playedCards;
	int currentPlayer_; //index of current player
	int seed_;
	//Table* table; //table of cards
};

#endif	/* GAME_H */

