
#include "Utils.h"

template < class T >
std::ostream& operator << (std::ostream& os, typename const std::vector<T>& v) 
{
    for (typename std::vector<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii){
        os << " " << *ii;
    }
	os << "\n";
    return os;
}

template < class T >
std::ostream& operator << (std::ostream& os, typename const std::vector< std::pair< T, T > >& v) 
{
    for (typename std::vector< std::pair< T, T > >::const_iterator ii = v.begin(); ii != v.end(); ++ii){
        os << "(" << *ii->first << " , " << *ii->second << ") ";
    }
	os << "\n";
    return os;
}
