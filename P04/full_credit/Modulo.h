#ifndef MODULO_H
#define MODULO_H

#include <iostream>

class Modulo{

public:

Modulo(int modulo =10, int value=0, int offset=0):_modulo{modulo},_value{value},_offset{offset} {};
void set_nmsd(Modulo*nmsd);
int value(); // returns _value
Modulo& operator+=(int rhs);
Modulo operator+(int rhs);

Modulo& operator++(); // Pre-increment

Modulo operator++(int ignore);// Post-increment with ignored variable

inline bool operator==(int rhs);
inline bool operator!=(int rhs);
inline bool operator<(int rhs);
inline bool operator<=(int rhs);
inline bool operator>(int rhs);
inline bool operator>=(int rhs);
friend std::ostream& operator<<(std::ostream& ost, Modulo& m); // done
friend std::ostream& operator>>(std::ostream& ost, Modulo& m);

private:
int _value;
int _modulo;
int _offset;
Modulo*_nmsd;
int compare(const int rhs);


};

#endif
