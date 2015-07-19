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
#include "UITableCards.h"
#include "UIPlayerOptions.h"
#include "UIPlayerCards.h"
#include "Observer.h"

class View : public Gtk::Window, public Observer {
public:
	View();
	virtual ~View();

private:
	//DeckGUI                         deck;             // Knows all of the card pixel buffers.

	// Member widgets:
	UIMenu							menu;
	UITableCards					tableCards;
	UIPlayerOptions					playerMenu;
	UIPlayerCards					playerCards;
	Gtk::Image                    *card[52];          // Images to display.
	Gtk::HBox                       hbox[4];          // Horizontal box for aligning widgets in the window.
	//Gtk::Frame                      frame;            // Create a nice framed border for the box.
	Gtk::VBox						vbox;

}; // View

#endif
