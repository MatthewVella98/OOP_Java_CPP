

#ifndef UNTITLED1_REPTILE_H
#define UNTITLED1_REPTILE_H
#include "animal.h"

class reptile : public Animal {


public:
    std::string venom;
    reptile *left, *right;


};

#endif //UNTITLED1_REPTILE_H
