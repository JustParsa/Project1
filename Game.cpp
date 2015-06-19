#include <iostream>
#include <cstdlib>
#include <random>
#include "Game.h"
#include "Player.h"
#include "Card.h"

const int CARD_COUNT = 52;

using namespace std;

Game::Game(vector<bool> humanPlayers, int seed) : seed_(seed), numCardsPlayed_(0){

	for (int x = 0; x < 4; x++) {
		players_[x] = new Player(humanPlayers.at(x), x);
	}
	
	initDeck();
	initPlayerCards();
	shuffle();
	currentPlayer_ = findFirstPlayer();
		
}

void Game::shuffle(){
	static mt19937 rng(seed_);

	int n = CARD_COUNT;

	while (n > 1) {
		int k = (int)(rng() % n);
		--n;
		Card *c = cards_[n];
		cards_[n] = cards_[k];
		cards_[k] = c;
	}
}

void Game::initDeck() {
	int i = 0;
	for (int suit = CLUB; suit < SUIT_COUNT; suit++) {
		for (int rank = ACE; rank < RANK_COUNT; rank++) {
			cards_[i] = new Card((Suit)suit, (Rank)rank);
			i++;
		}
	}
}

bool Game::isGameOver() const{
	return numCardsPlayed_ >= 52;
}

int Game::addAllPlayerPoints() const{

	for (int x = 0; x < 4; x++){
		players_[x]->sumTotalPoints();
	}

	int winner = players_[0]->getTotalPoints();
	bool greaterThanEightyPoints = false;

	for (int x = 0; x < 4; x++)
		if (players_[x]->getTotalPoints() >= 80)
			greaterThanEightyPoints = true;

	if (greaterThanEightyPoints)
		for (int x = 1; x < 4; x++)
			if (players_[x]->getTotalPoints() < winner)
				winner = players_[x]->getTotalPoints();

	greaterThanEightyPoints = (players_[0]->getTotalPoints() >= 80);

	if (greaterThanEightyPoints)
		return winner;
	return -1;
}

bool Game::numPointsGreaterThanEighty() const{

	for (int x = 0; x < 4; x++)
		if (players_[x]->getPoints() + players_[x]->getTotalPoints() >= 80)
			return true;

	return false;
}


void Game::initPlayerCards() {
	//distribute cards
	for (int currPlayer = 0; currPlayer < 4; currPlayer++) {
		for (int cardIndex = 0; cardIndex < 13; cardIndex++) {
			int currCard = currPlayer * 13 + cardIndex;
			Card* currentCard = cards_[currPlayer];
			players_[currPlayer]->addCard(*currentCard);
		}
	}
}

int Game::findFirstPlayer() {
	//distribute cards
	for (int currPlayer = 0; currPlayer < 4; currPlayer++) {
		for (int cardIndex = 0; cardIndex < 13; cardIndex++) {
			if (cards_[currPlayer]->getRank() == SEVEN && cards_[currPlayer]->getSuit() == SPADE)
				return currPlayer;
		}
	}
    return 0;
}

void Game::nextPlayer() {
	currentPlayer_++;
	if (currentPlayer_ > 4)
		currentPlayer_ = currentPlayer_ % 4;
}