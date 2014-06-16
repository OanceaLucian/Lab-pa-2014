/**
 * Proiectarea Algoritmilor, 2014
 * Lab 8: Drumuri minime
 * 
 * @author 	Radu Iacob
 * @email	radu.iacob23@gmail.com
 */
 
#include "Node.h"

Node::Node(uint id)
	: _city(""), _id(id), visited(false), parent(NULL)
{
}

Node::Node(std::string city, uint id)
	: _city(city), _id( id ), visited(false), parent(NULL)
{
}

void Node::set_parent( Node* parent )
{
	this->parent = parent;
}

Node* Node::get_parent() const
{
	return parent;
}


const uint Node::get_id() const
{
	return _id;
}

const std::string& Node::get_city() const
{
	return _city;
}

void Node::visit()
{
	visited = true;
}

bool Node::is_visited() const
{
	return visited;
}

void Node::reset()
{
	visited = false;
}

std::istream& operator>> (std::istream& in, Node& node)
{
	in >> node._city;
	return in;
}

std::ostream& operator<< (std::ostream& out, Node& node )
{
	out << "Node : " << node.get_city();
	return out;
}

std::ostream& operator<< (std::ostream& out, Node* node )
{
	out << *node;
	return out;
}
