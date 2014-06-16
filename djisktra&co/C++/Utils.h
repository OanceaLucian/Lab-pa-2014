
#ifndef UTILS_H
#define UTILS_H

/*
	C headers
*/

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cassert>

/*
	STL
*/

#include<map>
#include<set>
#include<queue>
#include<stack>
#include<string>
#include<vector>
#include<bitset>
#include<algorithm>
#include<functional>

#include<fstream>
#include<sstream>
#include<iostream>

typedef unsigned int uint;
const uint inf = 0x3f3f3f3f;

class InvalidQuery{
	
public:
	InvalidQuery( std::string error_msg ){
		std::cerr << "Invalid Query: " << error_msg << "\n";
	}
};

template< class T >
void check_in_range( T value, T range_start, T range_end )
{
	if( value < range_start || value > range_end )
	{
		std::cerr << value << " not in [ " << range_start;
		std::cerr << " , " << range_end << "\n";
		throw InvalidQuery("elem not in range");
	}
}


template < class T >
std::ostream& operator << (std::ostream& os, const typename std::vector<T>& v) 
{
	for (typename std::vector<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii){
		os << " " << *ii;	
	}

	os << "\n";

	return os;
}

template < class T >
std::ostream& operator << (std::ostream& os, const typename std::vector< std::pair< T, T > >& v) 
{
    for (typename std::vector< std::pair< T, T > >::const_iterator ii = v.begin(); ii != v.end(); ++ii){
        os << "(" << *ii->first << " , " << *ii->second << ") ";
    }
	os << "\n";
    return os;
}


#endif
