// //
// //  UIPlayerOptions.h
// //
// //  Created by Parsa Alipour on 2015-07-15.
// //  Copyright (c) 2015 Parsa Alipour. All rights reserved.
// //

#ifndef _UIPLAYEROPTIONS_
#define _UIPLAYEROPTIONS_

#include <stdio.h>
#include <gtkmm.h>
#include "UIPlayerOption.h"
#include "Observer.h"
#include "Controller.h"
#include "Game.h"

class UIPlayerOptions : public Gtk::HBox {
public:
    UIPlayerOptions();
    virtual ~UIPlayerOptions();
    void update();
private:
	Gtk::Frame						playerFrames[4];
    UIPlayerOption 					playerOptions[4];
};

#endif /* defined(_UIPLAYEROPTIONS_) */