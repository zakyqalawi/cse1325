#ifndef MAINWIN_H
#define MAINWIN_H


#include <gtkmm.h>
#include "store.h"


class Mainwin:public Gtk::Window{

public:

	Mainwin(); // default constructor
	virtual ~Mainwin(); // virtual destructor method

protected:

	void on_new_store_click(); //creates a new store
	void on_new_tool_click(); //creates a new tool
	void on_new_plant_click(); // creates a new plant
	void on_new_mulch_click();   // creates a new mulch
	void on_new_products_click();
	void on_view_products_click(); // creates a new product
	void on_quit_click(); // closes the window
	void on_open_click();
	void on_save_click();
	void on_save_as_click();
	void on_about_click();

private:
	Store *store;
	Gtk::Label *display;// text
	std::string filename;

	int get_int(std::string prompt);
	double get_double(std::string prompt);
	std::string get_string(std::string prompt);
};
#endif
