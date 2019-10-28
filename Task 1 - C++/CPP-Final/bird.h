

#ifndef UNTITLED1_BIRD_H
#define UNTITLED1_BIRD_H
#include "animal.h"


class bird : public Animal {


public:
    std::string fly;

    bird *left , *right;


};


#endif //UNTITLED1_BIRD_H
