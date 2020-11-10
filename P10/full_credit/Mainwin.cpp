#include "Mainwin.h"
#include "entrydialog.h"
#include <iostream>
#include <fstream>



Mainwin::Mainwin():store{nullptr},display{new Gtk::Label{}},filename{"Untitled"} {

set_default_size(940,780); // box size
set_title("Manga Magic"); // Title of box



Gtk::Box *vbox = Gtk::manage(new Gtk::VBox); // alocating box to the heap
add(*vbox);

Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar); 
vbox->pack_start(*menubar, Gtk::PACK_SHRINK);

	 msg= Gtk::manage(new Gtk::Label());
    msg->set_hexpand(true);
    vbox->pack_start(*msg, Gtk::PACK_SHRINK, 0);
   	vbox->show_all();

on_new_store_click();




//////////////////////////////FILE MENU TAB//////////////////////////////////////////////////////////////////// 

Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
menubar->append(*menuitem_file);
Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
menuitem_file->set_submenu(*filemenu);

Gtk::MenuItem *menuitem_new_store = Gtk::manage(new Gtk::MenuItem("_New Store",true));  // creating the quit menu item
menuitem_new_store->signal_activate().connect([this] {this->on_new_store_click();}); // linking the quit method
filemenu->append(*menuitem_new_store);

Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("_About",true));  // creating the quit menu item
menuitem_about->signal_activate().connect([this] {this->on_about_click();}); // linking the quit method
filemenu->append(*menuitem_about);

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

Gtk::MenuItem *menuitem_customer = Gtk::manage(new Gtk::MenuItem("_Customer",true));
menuitem_customer->signal_activate().connect([this] {this->on_customer_click();});
insertmenu->append(*menuitem_customer);

Gtk::MenuItem *menuitem_order= Gtk::manage (new Gtk::MenuItem("_Order",true));
menuitem_order->signal_activate().connect([this] {this->on_new_order_click();});
insertmenu->append(*menuitem_order);





//////////////////////////////////////// VIEW MENU TAB /////////////////////////////////////////////////////////


Gtk::MenuItem *menuitem_view = Gtk::manage(new Gtk::MenuItem("_View",true));
//menuitem_view->signal_activate().connect([this] {this->on_view_customer_click();});
menubar->append(*menuitem_view);

Gtk::Menu *viewmenu = Gtk::manage(new Gtk::Menu);
menuitem_view->set_submenu(*viewmenu);

Gtk::MenuItem *menuitem_customers = Gtk::manage(new Gtk::MenuItem("_Customers",true));
menuitem_customers->signal_activate().connect([this] {this->on_view_customers_click();});
viewmenu->append(*menuitem_customers);

Gtk::MenuItem *menuitem_products = Gtk::manage(new Gtk::MenuItem("_Products", true));
menuitem_products->signal_activate().connect([this] {this->on_view_products_click();});
viewmenu->append(*menuitem_products);

Gtk::MenuItem *menuitem_orders = Gtk::manage(new Gtk::MenuItem("_Orders", true));
menuitem_orders->signal_activate().connect([this] {this->on_view_orders_click();});
viewmenu->append(*menuitem_orders);
////////////////////////////////// TOOLBAR /////////////////////////////////////////////////////////////////////
Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
vbox->pack_start(*toolbar, Gtk::PACK_SHRINK, 0);

Gtk::ToolButton *new_store_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
new_store_button->set_tooltip_markup("Add a Store");
new_store_button->signal_clicked().connect([this] {this->on_new_store_click();});
toolbar->append(*new_store_button);

Gtk::ToolButton *open_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::OPEN));
open_button->set_tooltip_markup("Open a file");
open_button->signal_clicked().connect([this] {this->on_open_click();});
toolbar->append(*open_button);

Gtk::ToolButton *save_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::SAVE));
save_button->set_tooltip_markup("Save file");
save_button->signal_clicked().connect([this] {this->on_save_click();});
toolbar->append(*save_button);

Gtk::ToolButton *save_as_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::SAVE_AS));
save_as_button->set_tooltip_markup("Save as");
save_as_button->signal_clicked().connect([this] {this->on_save_as_click();});
toolbar->append(*save_as_button);

Gtk::ToolButton *new_customer_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::EDIT));
new_customer_button->set_tooltip_markup("Add a new customer");
new_customer_button->signal_clicked().connect([this] {this->on_customer_click();});
toolbar->append(*new_customer_button);

Gtk::ToolButton *new_tool_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::PROPERTIES));
new_tool_button->set_tooltip_markup("Add a new tool");
new_tool_button->signal_clicked().connect([this] {this->on_new_tool_click();});
toolbar->append(*new_tool_button);

Gtk::ToolButton *new_plant_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::REFRESH));
new_plant_button->set_tooltip_markup("Add a new plant");
new_plant_button->signal_clicked().connect([this] {this->on_new_plant_click();});
toolbar->append(*new_plant_button);

Gtk::ToolButton *new_mulch_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::ABOUT));
new_mulch_button->set_tooltip_markup("Add a new mulch");
new_mulch_button->signal_clicked().connect([this] {this->on_new_mulch_click();});
toolbar->append(*new_mulch_button);

Gtk::ToolButton *view_customers_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::ZOOM_FIT));
view_customers_button->set_tooltip_markup("view customers");
view_customers_button->signal_clicked().connect([this] {this->on_view_customers_click();});
toolbar->append(*view_customers_button);



Gtk::ToolButton *new_order_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::MISSING_IMAGE));
new_order_button->set_tooltip_markup("Add a new Order");
new_order_button->signal_clicked().connect([this] {this->on_new_order_click();});
toolbar->append(*new_order_button);

Gtk::ToolButton *view_orders_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::JUMP_TO));
view_orders_button->set_tooltip_markup("View Orders");
view_orders_button->signal_clicked().connect([this] {this->on_view_orders_click();});
toolbar->append(*view_orders_button);

Gtk::ToolButton *view_plants_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::APPLY));
view_plants_button->set_tooltip_markup("View Plants");
view_plants_button->signal_clicked().connect([this] {this->on_view_plants_click();});
toolbar->append(*view_plants_button);
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
Store store(ist);
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
void  Mainwin::on_about_click() {
 Gtk::AboutDialog dialog;
 dialog.set_transient_for(*this); 
 dialog.set_program_name("Manga");
	auto logo = Gdk::Pixbuf::create_from_file("logo.jpg");
 dialog.set_logo(logo);
 dialog.set_version("Version 12");
 dialog.set_copyright("Copyright 2020");
 dialog.set_license_type(Gtk::License::LICENSE_GPL_3_0);
 std::vector< Glib::ustring > authors = {"Zaky B. Qalawi"};
 dialog.set_authors(authors);
 std::vector< Glib::ustring > artists = {
 "Logo by Louis Hansel, https://unsplash.com/photos/Rf9eElW3Qxo"};
dialog.set_artists(artists);
 dialog.run();
}


void Mainwin::on_new_store_click() {
    delete store;
	std::string name = get_string("Store Name?");
    store = new Store{name};
	set_status();
}

////////////////////////////////////////// INSERT METHODS /////////////////////////////////////////////////

void Mainwin::on_new_tool_click() {
    try {
        std::string name = get_string("Name?");
        double price = get_double("Price?");
        std::string description = get_string("Description?");
        store->add_product(*(new Tool{name, price, description}));
        //on_view_products_click();
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
        //on_view_products_click();
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
        //on_view_products_click();
    } catch(std::exception& e) {
    }
}

void Mainwin::on_new_order_click(){

Gtk::Dialog dialog{"Order for which Customer?", *this};


Gtk::ComboBoxText combo{true};

for(int i =0; i<store->customers(); i++){
std::ostringstream oss;
oss<< store-> customer(i);
combo.append(oss.str());
}

//combo.append("test");
combo.set_active(0);
dialog.get_content_area()->pack_start(combo,Gtk::PACK_SHRINK);
dialog.add_button("Start Order", 1);
dialog.add_button("Cancel",0);
dialog.show_all();
dialog.run();
/*
std::string name;

 while(dialog.run()) {
        try {
            name = E_name.get_text();
            if(name.empty()) {E_name.set_text("### Required ###"); continue;}
            Customer customer{name, 
                              E_num.get_text(),
                              E_mail.get_text()};
            store->add_customer(customer);
            break;
        } catch(std::exception& e) {
            Gtk::MessageDialog{*this, "Unable to create new customer " + name 
                                    + ": " + std::string{e.what()},
                false, Gtk::MESSAGE_WARNING}.run();
            break;
        }
    }}*/

};

void Mainwin::on_customer_click(){
	set_status();
    try {
        /*std::string name = get_string("Name?");
        std::string num = get_string("Phone Number?");
        std::string email = get_string("Email?");
        */

Gtk::Dialog dialog{"Insert Customer", *this};
Gtk::Grid grid;

Gtk::Label C_name{"Name"};
Gtk::Entry E_name;

grid.attach(C_name, 0, 0, 1, 1);
grid.attach(E_name, 1,0,2,1);

Gtk::Label C_num{"Phone"};
Gtk::Entry E_num;

grid.attach(C_num, 0, 1, 1, 1);
grid.attach(E_num, 1,1,2,1);

Gtk::Label C_mail{"Email"};
Gtk::Entry E_mail;

grid.attach(C_mail, 0, 2, 1, 1);
grid.attach(E_mail, 1,2,2,1);

dialog.get_content_area()->add(grid);

dialog.add_button("Insert", 1);
dialog.add_button("Cancel",0);
dialog.show_all();

std::string name;

 while(dialog.run()) {
        try {
            name = E_name.get_text();
            if(name.empty()) {E_name.set_text("### Required ###"); continue;}
            Customer customer{name, 
                              E_num.get_text(),
                              E_mail.get_text()};
            store->add_customer(customer);
            break;
        } catch(std::exception& e) {
            Gtk::MessageDialog{*this, "Unable to create new customer " + name 
                                    + ": " + std::string{e.what()},
                false, Gtk::MESSAGE_WARNING}.run();
            break;
        }
    }}

 catch(std::exception& e) {
    }



};

void Mainwin::on_order_click(){};
///////////////////////////////////////////	  VIEW METHODS 	///////////////////////////////////////////////////

void Mainwin::on_view_products_click() {
    std::string s = "Current Products\n----------------\n\n";
    for(int i=0; i<store->products(); ++i) {
        std::ostringstream oss;
        oss << store->product(i) << '\n';
        s += oss.str();
    }
    display->set_text(s);
}

void Mainwin:: on_view_orders_click(){
 std::string s = "Current Orders\n----------------\n\n";
  /*  for(int i=0; i<store->orders(); ++i) {
        std::ostringstream oss;
        oss << store->order(i) << '\n';
        s += oss.str();
    }*/
    display->set_text(s);


};
//void Mainwin:: on_view_customers_click(){};
void Mainwin:: on_view_plants_click(){
std::string s = "Current Plants\n----------------\n\n";
 for(int i=0; i<store->products(); ++i) {
        std::ostringstream oss;
        oss << store->product(i) << '\n';
        s += oss.str();
    }
    display->set_text(s);


};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Mainwin::on_quit_click() {
    close();
}

void Mainwin::on_view_customers_click() {
    std::string s = "Current Customers\n----------------\n\n";
    for(int i=0; i<store->customers(); ++i) {
        std::ostringstream oss;
        oss << store->customer(i) << '\n';
        s += oss.str();
    
    display->set_text(s);

}}




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

void Mainwin::set_status() {
    Glib::ustring s = "";
 s += "Created New Store";
    msg->set_markup(s);

    

}


