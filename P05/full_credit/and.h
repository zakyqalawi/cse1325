#ifndef AND_H
#define AND_H
#include"Gate.h"

class And : public Gate{
public:
And(Signal _input1,Signal _input2);
Signal output() override;
};

#endif  
