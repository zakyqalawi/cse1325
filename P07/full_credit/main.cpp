 #include "tool.h"
#include "plant.h"
#include "mulch.h"
#include "Mainwin.h"


int main(int argc, char *argv[]){
 
auto app = Gtk::Application::create(argc, argv, "edu.uta.cse1325.manga");
Mainwin win;
return app->run(win);
}












/*
int main() {

    Tool tool("Spade", 5.99, "Digs in the dirt");
    std::cout << tool << std::endl;
    Plant plant("Clover", 1.59, "It bee sweet!", "T. pratense", Exposure::SUN);
    std::cout << plant << std::endl;
    Mulch mulch("Red Cedar Mulch", 6.99, "Smells heavenly!", 2.0, Material::CEDAR);
    std::cout << mulch << std::endl;
}

*/
