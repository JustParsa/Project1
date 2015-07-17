// //
// //  UIPlayerOption.cc
// //
// //  Created by Parsa Alipour on 2015-07-15.
// //  Copyright (c) 2015 Parsa Alipour. All rights reserved.
// //

#include <gtkmm.h>
#include "UIPlayerOption.h"

UIPlayerOption::UIPlayerOption() : pointsLbl("Points: 0"), discardsLbl("Discards: 0"), togglePlayerBtn("Human") {
	this->set_border_width(4);
	this->set_spacing(3);
	add(togglePlayerBtn);
	add(pointsLbl);
	add(discardsLbl);
}

UIPlayerOption::~UIPlayerOption() {};

