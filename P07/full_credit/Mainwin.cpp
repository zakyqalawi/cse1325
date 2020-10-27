#include "Mainwin.h"
#include "entrydialog.h"
#include <iostream>
#include <fstream>



Mainwin::Mainwin():store{nullptr},display{new Gtk::Label{}},filename{"Untitled"} {

set_default_size(200,400); // box size
set_title("Manga Magic"); // Title of box



Gtk::Box *vbox = Gtk::manage(new Gtk::VBox); // alocating box to the heap
add(*vbox);

Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar); 
vbox->add(*menubar);

//////////////////////////////FILE MENU TAB//////////////////////////////////////////////////////////////////// 

Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
menubar->append(*menuitem_file);
Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
menuitem_file->set_submenu(*filemenu);

Gtk::MenuItem *menuitem_new_store = Gtk::manage(new Gtk::MenuItem("_New_Store",true));  // creating the quit menu item
menuitem_new_store->signal_activate().connect([this] {this->on_new_store_click();}); // linking the quit method
filemenu->append(*menuitem_new_store);


Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit",true));  // creating the quit menu item
menuitem_quit->signal_activate().connect([this] {this->on_quit_click();}); // linking the quit method
filemenu->append(*menuitem_quit);

Gtk::MenuItem *menuitem_open = Gtk::manage(new Gtk::MenuItem("_Open",true));  // creating the open menu item
menuitem_open->signal_activate().connect([this] {this->on_open_click();}); // linking the open click method
filemenu->append(*menuitem_open);

Gtk::MenuItem *menuitem_save_as = Gtk::manage(new Gtk::MenuItem("_Save_As",true));  // creating the save as menu item
menuitem_save_as->signal_activate().connect([this] {this->on_save_as_click();}); // linking the save as click method
filemenu->append(*menuitem_save_as);

Gtk::MenuItem *menuitem_save = Gtk::manage(new Gtk::MenuItem("_Save",true));  // creating the save as menu item
menuitem_save->signal_activate().connect([this] {this->on_save_click();}); // linking the save as click method
filemenu->append(*menuitem_save);

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

////////////////////////////////// OPEN CLICK /////////////////////////////////////////////////////////////////










display = Gtk::manage(new Gtk::Label());
    display->set_hexpand(true);
    display->set_vexpand(true);
    vbox->add(*display);


vbox->show_all();


}

void Mainwin::on_open_click() {
 
Gtk::FileChooserDialog dialog("Choose a file", Gtk::FileChooserAction::FILE_CHOOSER_ACTION_OPEN);
 dialog.set_transient_for(*this);
 
 dialog.add_button("_Cancel", 0);
 dialog.add_button("_Open", 1);
 int result = dialog.run();
 if (result == 1) {
std::ifstream ist{filename};
std::string input;
while(std::getline(ist,input)){
	std::cout<<input<<std::endl;
 }
}}

void Mainwin::on_save_as_click() {
 
Gtk::FileChooserDialog dialog("Choose a file", Gtk::FileChooserAction::FILE_CHOOSER_ACTION_SAVE);
 dialog.set_transient_for(*this);

 dialog.add_button("_Cancel", 0);
 dialog.add_button("_Open", 1);
 int result = dialog.run();
 if (result == 1) {
try{
		std::ofstream ofs{dialog.get_filename()};
		store->save(ofs);
	
 }catch(std::exception e){
	Gtk::MessageDialog{*this, "File saving error"}.run();
}}}

void Mainwin::on_save_click(){

try{
	std::ofstream ofs{filename};
	store->save(ofs);
	}catch(std::exception e){
			Gtk::MessageDialog{*this, "Error saving data", false, Gtk::MESSAGE_ERROR}.run();
}}

;


///////////////////////////////////////////////////////////////////////////////////////////////////////////////}


Mainwin::~Mainwin() { }

void Mainwin::on_new_store_click() {
    delete store;
	std::string name = get_string("Store Name?");
    store = new Store{name};
}

void Mainwin::on_new_tool_click() {
    try {
        std::string name = get_string("Name?");
        double price = get_double("Price?");
        std::string description = get_string("Description?");
        store->add_product(*(new Tool{name, price, description}));
        on_view_products_click();
    } catch(std::exception& e) {
    }
}

void Mainwin::on_new_plant_click() {
    try {
        std::string name = get_string("Name?");
        double price = get_double("Price?");
        std::string description = get_string("Description?");
        std::string species = get_string("Species?");
        double d = get_double("Exposure? (1) Shade (2) Part Sun (3) Sun");
        Exposure exposure = (d==1.0) ? Exposure::SHADE : ((d==3.0) ? Exposure::SUN : Exposure::PARTSUN);
        store->add_product(*(new Plant{name, price, description, species, exposure}));
        on_view_products_click();
    } catch(std::exception& e) {
    }
}

void Mainwin::on_new_mulch_click() {
    try {
        std::string name = get_string("Name?");
        double price = get_double("Price?");
        std::string description = get_string("Description?");
        int volume = get_int("Volume (ft³)?");
        int i = get_int("Material? (1) Rubber (2) Pine (3) Cedar (4) Hardwood");
        Material material;
        if(i == 1)       material = Material::RUBBER;
        else if (i == 2) material = Material::PINE;
        else if (i == 3) material = Material::CEDAR;
        else             material = Material::HARDWOOD;
        store->add_product(*(new Mulch{name, price, description, volume, material}));
        on_view_products_click();
    } catch(std::exception& e) {
    }
}

void Mainwin::on_view_products_click() {
    std::string s = "Current Products\n----------------\n\n";
    for(int i=0; i<store->products(); ++i) {
        std::ostringstream oss;
        oss << store->product(i) << '\n';
        s += oss.str();
    }
    display->set_text(s);
}

void Mainwin::on_quit_click() {
    close();
}

std::string Mainwin::get_string(std::string prompt) {
    EntryDialog edialog(*this, "<big>New Product</big>", true, Gtk::MESSAGE_QUESTION, Gtk::BUTTONS_OK_CANCEL);
    edialog.set_secondary_text(prompt, true);
    if(edialog.run() == Gtk::RESPONSE_CANCEL) throw std::runtime_error{"CANCEL"};
    return edialog.get_text();
}

double Mainwin::get_double(std::string prompt) {
    while(true) {
        try {
            return std::stod(get_string(prompt));
        } catch (std::invalid_argument& e) {
            prompt = "Invalid value, please try again:";
        }
    }
}

int Mainwin::get_int(std::string prompt) {
    while(true) {
        try {
            return std::stoi(get_string(prompt));
        } catch (std::invalid_argument& e) {
            prompt = "Invalid value, please try again:";
        }
    }
}



