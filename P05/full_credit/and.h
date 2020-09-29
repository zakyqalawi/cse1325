#ifndef AND_H
#define AND_H
#include"Gate.h"

class And : public Gate{
public:
Signal output() override;
};

#endif  
