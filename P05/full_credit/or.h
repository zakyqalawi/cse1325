#ifndef OR_H
#define OR_H
#include"Gate.h"

class Or : public Gate{
public:
Or():Gate(){};
Signal output() override;
};

#endif  
