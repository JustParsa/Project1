// //
// //  UIMenu.h
// //
// //  Created by Parsa Alipour on 2015-07-15.
// //  Copyright (c) 2015 Parsa Alipour. All rights reserved.
// //

#ifndef __UIMenu__
#define __UIMenu__

#include <stdio.h>
#include <gtkmm.h>
#include "View.h"
#include "Observer.h"
// #include "Controller.h"
// #include "Game.h"

class View;

class UIMenu : public Gtk::HBox, public Observer {
public:
    UIMenu(View&);
    virtual ~UIMenu();
    void update();
private:
    Gtk::Button                     startGameBtn;
    Gtk::Button 					endGameBtn;
    Gtk::Entry						seedEntry;
    View& 							view_;
    void startNewGame();
    void endGame();

};

#endif /* defined(__UIMenu__) */
