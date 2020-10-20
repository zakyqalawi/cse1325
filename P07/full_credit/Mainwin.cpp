 #include "Mainwin.h"
#include <iostream>

/*Mainwin::Mainwin(): store{new Gtk::Store}{
	add (*store);
	store->signal_clicked().connect([this] {this->on_new_store_click();});
	store->show
}*/

Mainwin::Mainwin(){

set_default_size(400,200);
set_title("MANGA");

display= Gtk::manage(new Gtk::Label{get_string}, Gtk::{ALIGN_CENTER});
add(*display);
display->show();


Gtk::Box *vbox = Gtk::manage(new Gtk::VBox); // alocating box to the heap
add(*vbox);

Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar); 
vbox->add(*menubar);

//////////////////////////////FILE MENU TAB//////////////////////////////////////////////////////////////////// 

Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
menubar->append(*menuitem_file);
Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
menuitem_file->set_submenu(*filemenu);

Gtk::Menuitem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit",true));  // creating the quit menu item
menuitem_quit->signal_activate().connect([this] {this->on_quit_click();}); // linking the quit method

///////////////////////////////////// INSERT MENU TAB /////////////////////////////////////////////////////////

Gtk::MenuItem *menuitem_insert = Gtk::manage(new Gtk::MenuItem("_Insert", true));
menubar->append(*menuitem_insert);
Gtk::Menu *insertmenu = Gtk::manage(new Gtk::Menu());
menuitem_insert->set_submenu(*insertmenu);

Gtk::MenuItem *menuitem_tool = Gtk::manage(new Gtk::MenuItem("_Tool",true));
menuitem_tool->signal_activate().connect([this] {this->on_new_tool_click();});
insertmenu->append(*menuitem_tool);

Gtk::MenuItem *menuitem_plant = Gtk::manage(new Gtk::MenuItem("_Plant",true));
menuitem_plant->signal_activate().connect([this] {this->on_new_plant_click();});
insertmenu->append(*menuitem_plant);

Gtk::MenuItem *menuitem_mulch = Gtk::manage(new Gtk::MenuItem("_Mulch",true));
menuitem_mulch->signal_activate().connect([this] {this->on_new_mulch_click();});
insertmenu->append(*menuitem_mulch);

vbox->show_all;

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////}
void on_quit_click(){
close;
}




//Mainwin::~Mainwin() {}




//Gtk::Store *store;
	
