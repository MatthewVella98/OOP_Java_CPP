
#ifndef UNTITLED1_MAMMAL_H
#define UNTITLED1_MAMMAL_H

#include "animal.h"


class mammal : public Animal {

public:
    int litter;
    mammal *left ,*right ;


};

#endif //UNTITLED1_MAMMAL_H
