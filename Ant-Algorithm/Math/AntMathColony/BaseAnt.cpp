#include "BaseAnt.hpp"

// Constructor BaseAnt(math::obj::ptrPoint&, vector<math::obj::ptrPoint>&)
BaseAnt::BaseAnt( obj::ptrPoint& start, std::vector< obj::ptrPoint >& vec )
{
    if (vec.size() <= 2)
        throw SizeError();
    
    this->start = start;
    for ( std::size_t i = 0; i < vec.size(); i++ )
    {

        if ( vec[i] != start )
        {   
            auto hashablePointPtr = std::static_pointer_cast<math::HashablePoint>(vec[i]);
            novisit->insert( hashablePointPtr );
        }
    }
    
}

