#include "Mainwin.h"
#include "entrydialog.h"
#include <iostream>



Mainwin::Mainwin():store{nullptr},display{new Gtk::Label{}}{

set_default_size(400,200); // box size
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

Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit",true));  // creating the quit menu item
menuitem_quit->signal_activate().connect([this] {this->on_quit_click();}); // linking the quit method
filemenu->append(*menuitem_quit);

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


display = Gtk::manage(new Gtk::Label());
    display->set_hexpand(true);
    display->set_vexpand(true);
    vbox->add(*display);


vbox->show_all();
on_new_store_click();

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////}
void on_quit_click(){
close;
}


Mainwin::~Mainwin() { }

void Mainwin::on_new_store_click() {
    delete store;
    store = new Store{"Untitled"};
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



