/**
 * Proiectarea Algoritmilor, 2013
 * Lab 7: Aplicatii DFS
 * 
 * @author 	Radu Iacob
 * @email	radu.iacob23@gmail.com
 */
 
#include "Node.h"

Node::Node( uint id ) : _name( "" ), _id( id ),
						level( UNSET ), lowlink( UNSET ),
						ctc_index( UNSET ), sum( UNSET )
{
	_prop[ CTC ] = UNSET;
	in_stack     = false;
}

Node::Node( std::string name, uint id ) : _name( name ), _id( id ),
										  level( UNSET ), lowlink( UNSET ),
										  ctc_index( UNSET ), sum( UNSET )
{
	_prop[ CTC ] = UNSET;
	in_stack = false;
}

const uint Node::get_id() const
{
	return _id;
}

const std::string& Node::get_name() const
{
	return _name;
}

bool Node::visited()
{
	return level != UNSET;
}

int Node::get_property( Property p )
{
	return _prop[ p ];
}

void Node::set_property( Property p, int value )
{
	_prop[ p ] = value;
}

std::istream& operator>> (std::istream& in, Node& node) 
{
	in >> node._name;
	return in;
}

std::ostream& operator<< (std::ostream& out, Node& node )
{
	out << "Node : ";
	//if( node._name.size() != 0 ) out << node._name << " , ";
	out << "id: " << node._id;   
	
	return out;
}

std::ostream& operator<< (std::ostream& out, Node* node )
{
	out << *node;
	return out;
}
