// //
// //  UIMenu.h
// //  Deliverable1
// //
// //  Created by Parsa Alipour on 2015-07-15.
// //  Copyright (c) 2015 Parsa Alipour. All rights reserved.
// //

#ifndef __Deliverable1__UIMenu__
#define __Deliverable1__UIMenu__

#include <stdio.h>
#include <gtkmm.h>

class UIMenu : public Gtk::HBox {
public:
    UIMenu();
    virtual ~UIMenu();
private:
    Gtk::Button                     startGameBtn;
    Gtk::Button 					endGameBtn;
    Gtk::Entry						seedEntry;

};

#endif /* defined(__Deliverable1__UIMenu__) */
