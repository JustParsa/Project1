#ifndef CONTROLLER_H
#define	CONTROLLER_H

#include "Game.h"

class Controller {
public:
    Controller(Game&);
    void eventNewGame(std::string seed);
    void eventEndGame();
    void eventRageQuit();
    void eventSetPlayerType(int, bool);
    void eventCardSelect(Card);
private:
    Game& model_;
};

#endif	/* CONTROLLER_H */

