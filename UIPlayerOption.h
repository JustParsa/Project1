// //
// //  UIPlayerOption.h
// //
// //  Created by Parsa Alipour on 2015-07-15.
// //  Copyright (c) 2015 Parsa Alipour. All rights reserved.
// //

#ifndef _UIPLAYEROPTION_
#define _UIPLAYEROPTION_

#include <stdio.h>
#include <gtkmm.h>
#include "Game.h"
#include "View.h"

class View;

class UIPlayerOption : public Gtk::VBox {
public:
    UIPlayerOption(View&, Game&);
    virtual ~UIPlayerOption();
    void update();
private:
    Gtk::VBox                   	playerInfo;
    Gtk::Button						togglePlayerBtn;
    Gtk::Label						pointsLbl;
    Gtk::Label						discardsLbl;
    View&							view_;
    Game&							model_;
};

#endif /* defined(_UIPLAYEROPTION_) */