#pragma once

#include <memory>
#include <string>

class Animal {

private:

    std::string name;
    int length;

public:

    std::string GetName() {
        return name;
    }
    int GetLength(){
        return length;
    }

    void SetName(std::string name) {this -> name = name;}
    void SetLength(int length){this-> length = length;}


};


//void SetWeight(double weight) { this->weight = weight; }



