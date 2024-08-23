//  Created by Семён Шестаков on 23.12.2023.
#ifndef BaseAnt_hpp
#define BaseAnt_hpp

#include "PointObject.hpp"
#include <unordered_set>


class SizeError : public std::exception {};
class NullPointer : public std::exception {};


using math::setPoint, std::unique_ptr;


class BaseAnt
{
protected:
    class AntConstructor : public std::exception{};
    obj::ptrPoint start = NULL;
    unique_ptr< setPoint > visit = std::make_unique< setPoint >();
    unique_ptr< setPoint > novisit = std::make_unique< setPoint >();
    
public:
    BaseAnt() { throw AntConstructor(); };
    BaseAnt( obj::ptrPoint&, std::vector< obj::ptrPoint >& );
};

#endif /* BaseAnt_hpp */
