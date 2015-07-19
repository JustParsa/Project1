#include "Controller.h"
#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

Controller::Controller(Game& game) : model_(game) {
}

void Controller::eventNewGame(string seed) {
    int intSeed = stoi(seed);
    model_.changeSeed(intSeed);
    model_.newGame();
}

void Controller::eventEndGame() {
    model_.endGame();
}

void Controller::eventRageQuit() {
    model_.humanRageQuit();
}

void Controller::eventSetPlayerType(int index, bool isPlayerHuman) {
    model_.changePlayerType(index, isPlayerHuman);
}

void Controller::eventCardSelect(Card card) {

    model_.playCard(model_.getPointerToCard(card));

}
