// //
// //  UIPlayerOptions.cc
// //
// //  Created by Parsa Alipour on 2015-07-15.
// //  Copyright (c) 2015 Parsa Alipour. All rights reserved.
// //

#include <gtkmm.h>
#include <string>
#include "UIPlayerOptions.h"

UIPlayerOptions::UIPlayerOptions() {
	this->set_spacing(3);
	for (int i = 0; i < 4; ++i) {
		playerFrames[i].set_label("Player " + std::to_string(i+1));
		add(playerFrames[i]);
		playerFrames[i].add(playerOptions[i]);
	}
}

UIPlayerOptions::~UIPlayerOptions() {}

