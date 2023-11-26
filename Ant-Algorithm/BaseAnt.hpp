//  Created by Семён Шестаков on 23.12.2023.
#ifndef BaseAnt_hpp
#define BaseAnt_hpp

#include "point.hpp"
#include <unordered_set>

typedef unordered_set<ptrPoint, Point::SharedPtrHash, Point::SharedPtrEqual> setPoint;

class AntConstructor : public exception{};
class SizeError : public exception {};
class NullPointer : public exception {};

class BaseAnt{
protected:
    ptrPoint start = NULL;
    unique_ptr<unordered_set<ptrPoint, Point::SharedPtrHash, Point::SharedPtrEqual>> visit = make_unique<setPoint>();
    unique_ptr<unordered_set<ptrPoint, Point::SharedPtrHash, Point::SharedPtrEqual>> novisit = make_unique<setPoint>();
public:
    BaseAnt();
    BaseAnt(ptrPoint&, vector<ptrPoint>&);
};

#endif /* BaseAnt_hpp */
