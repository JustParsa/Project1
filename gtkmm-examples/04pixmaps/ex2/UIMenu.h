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
//#include "Controller.h"

class UIMenu : public Gtk::HBox, public Observer {
public:
    UIMenu();
    virtual ~UIMenu();

private:
    Gtk::Button                     startGameBtn;
    Gtk::Button 					endGameBtn;
    Gtk::Entry						seedEntry;
    // Controller						controller_;
    void startNewGame();
    void endGame();

};

#endif /* defined(__UIMenu__) */
