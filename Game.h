#ifndef GAME_H
#define	GAME_H

#include "Card.h"
#include "Player.h"
#include "PlayedCards.h"
#include <vector>
#include <string>

class Game {
public:
	Game(std::vector<bool> humanPlayers, int);		//Initialises the deck, the players, shuffles the deck, distributes the cards
	
	//virtual ~Game();
	void newRound();
	void initDeck();
	void initPlayerCards();
	int findFirstPlayer();
	void shuffle();
	bool numPointsGreaterThanEighty() const;
	void nextPlayer();
	void playCard(Card *card, std::string);
	void discardCard(Card *card, std::string);
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
	std::vector<Card*> getDiscardedCards(int) const;
	void printScore();
private:
	Card* cards_[52]; //all cards of the deck
	Player* players_[4]; //all the players of the game
	PlayedCards playedCards; //The cards on the table
	int currentPlayer_; //The current player
	int seed_;
};

#endif	/* GAME_H */

