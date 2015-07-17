#ifndef __OTHER_WORLD_H
#define __OTHER_WORLD_H

// #include <gtkmm/window.h>
// #include <gtkmm/image.h>
// #include <gtkmm/box.h>
// #include <gtkmm/button.h>
// #include <gtkmm/frame.h>
#include <gtkmm.h>

#include "DeckGUI.h"
#include "UIMenu.h"
#include "UIPlayerOptions.h"

class OtherWorld : public Gtk::Window {
public:
	OtherWorld();
	virtual ~OtherWorld();

private:
	DeckGUI                         deck;             // Knows all of the card pixel buffers.

	// Member widgets:
	UIMenu							menu;
	UIPlayerOptions					playerMenu;
	Gtk::Image                    *card[52];          // Images to display.
	Gtk::HBox                       hbox[4];          // Horizontal box for aligning widgets in the window.
	//Gtk::Frame                      frame;            // Create a nice framed border for the box.
	Gtk::VBox						vbox;
	// Gtk::HBox 						menu;
}; // OtherWorld

#endif
