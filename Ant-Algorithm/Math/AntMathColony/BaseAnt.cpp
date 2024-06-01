#include "BaseAnt.hpp"

// Constructor BaseAnt(ptrPoint&, vector<ptrPoint>&)
BaseAnt::BaseAnt(ptrPoint& start, vector<ptrPoint>& vec){
    if (vec.size() <= 2){ throw SizeError();}
    this->start = start;
    for (size_t i = 0; i < (vec.size());i++){
        if (*vec[i] != *start){ novisit->insert(vec[i]);}
    }
}

