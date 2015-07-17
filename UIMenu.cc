// //
// //  UIMenu.cpp
// //  Deliverable1
// //
// //  Created by Parsa Alipour on 2015-07-15.
// //  Copyright (c) 2015 Parsa Alipour. All rights reserved.
// //

#include <gtkmm.h>
#include "UIMenu.h"

class Otherworld;

UIMenu::UIMenu() : startGameBtn("Start Game"), endGameBtn("End Game") {
    add(startGameBtn);
    add(seedEntry);
    add(endGameBtn);
    seedEntry.set_text("0");
    seedEntry.set_alignment(0.5);
};

UIMenu::~UIMenu() {};