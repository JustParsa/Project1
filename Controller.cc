/*
 * File:   Controller.cpp
 * Author: nigelchan
 *
 * Created on July 10, 2012, 9:18 PM
 */

#include "Controller.h"
#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

Controller::Controller(Game& game) : model_(game) {
}

void Controller::eventNewGame(string seed) {
    int intSeed = stoi(seed);            //Convert the passed string to an integer
    model_.changeSeed(intSeed);
    model_.newGame();
}

void Controller::eventEndGame() {
    model_.endGame();                  //Call the game function End Game
}

void Controller::eventRageQuit() {
    model_.humanRageQuit();                //Call the game function Rage Quit
}

void Controller::eventSetPlayerType(int index, bool isPlayerHuman) {
    model_.changePlayerType(index, isPlayerHuman);
}

void Controller::eventCardSelect(Card card) {

    model_.playCard(model_.getPointerToCard(card));

}


/**
 * Parse the given number in string format into an integer
 *
 * @param input - given number in string format
 * @param output - parsed integer will be stored in this variable if parsed successfully
 * @return true if parsed successfully. False otherwise.
 * @modifies output to the parsed integer
 */
bool Controller::parseInt(const string& input, int& output) {
    bool isNegative = false;
    output = 0;
    for (string::size_type i = 0; i < input.length(); ++i) {
        char c = input.at(i);
        //check if the character is a digit
        //if true, shift all numbers to the left by one and add the new digit
        if (c >= '0' && c <= '9')
            output = output * 10 + c - '0';
        else if (c == '-' && i == 0)
            isNegative = true;
        else
            return false;
    }
    //change the sign of the number if front of the string contains '-'
    if (isNegative)
        output = -output;
    return true;
}
