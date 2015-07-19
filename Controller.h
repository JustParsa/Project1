#ifndef CONTROLLER_H
#define	CONTROLLER_H

#include "Game.h"

class Controller {
public:
    Controller(Game&);
    void eventNewGame(std::string seed); //NumberFormatException will be thrown if seed is an invalid integer
    void eventEndGame();
    void eventRageQuit();
    void eventSetPlayerType(int, bool);
    void eventCardSelect(Card);
private:
    Game& model_;
    bool parseInt(const std::string& input, int& output); //parse given string into an integer
};

#endif	/* CONTROLLER_H */

