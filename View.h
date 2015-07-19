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
#include "Controller.h"

class UIMenu;
class UITableCards;
class UIPlayerOptions;
class UIPlayerCards;

class View : public Gtk::Window, public Observer {
public:
	View(Game&, Controller&);
	virtual ~View();
	void update();
	void startNewGame(std::string);
	void endGame();
	void eventRageQuit();
	void eventCardSelect(Card*);
	void eventSetPlayerType(int, bool);
	void updateDiolog();
    void updateRoundComplete();
    void updateGameOver();

private:
	//DeckGUI                         deck;             // Knows all of the card pixel buffers.

	// Member widgets:
	UIMenu*							menu;
	UITableCards*					tableCards;
	UIPlayerOptions*				playerMenu;
	UIPlayerCards*					playerCards;
	Gtk::Label						playerHandLbl;
	Gtk::Image                    	*card[52];          // Images to display.
	Gtk::HBox                       hbox[4];          // Horizontal box for aligning widgets in the window.
	//Gtk::Frame                      frame;            // Create a nice framed border for the box.
	Gtk::VBox						vbox;
	Game& 							model_;
	Controller& 					controller_;

}; // View

#endif
