/* 
 * File:   main.cpp
 * Author: nigel
 * 
 * Created on July 8, 2012, 4:04 PM
 */

#include <gtkmm.h>
#include "View.h"
#include "CurrentHandDisplay.h"
#include <iostream>
#include <deque>
#include <cstdlib>
#include "Command.h"
#include "Game.h"
#include "Controller.h"
#include "Action.h"
#include "IllegalPlayException.h"
#include "IllegalDiscardException.h"


using namespace std;

int main(int argc, char* argv[]) {   
    Gtk::Main kit(argc, argv);
    Game game;
    Controller controller(game);
    View view(controller, game);
    Gtk::Main::run(view);
    return 0;
}
 
