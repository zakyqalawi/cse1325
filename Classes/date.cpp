#include "date.h"

 Date::Date(int _month, int _day, int _year):month{_month},day{_day},year{_year}{}




void Date::print_(){

std::cout<< month<<'/'<<day<<'/'<<year<<std::endl;

}



