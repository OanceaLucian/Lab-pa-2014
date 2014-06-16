/**
 * Proiectarea Algoritmilor, 2014
 * Lab 8: Drumuri minime
 * 
 * @author 	Radu Iacob
 * @email	radu.iacob23@gmail.com
 */
 
#ifndef NODE_H
#define NODE_H

#include "Utils.h"

class Node {

	std::string _city;
	uint _id;
	bool visited;
	
	Node* parent;

public:

	Node(std::string city, uint id);
	Node(uint id);
	
	const std::string& get_city() const;
	const uint get_id() const;

	void visit();
	bool is_visited() const;
	void reset();

	void  set_parent( Node* parent );
	Node* get_parent() const;

	friend std::istream& operator>> (std::istream& in , Node& node);
	friend std::ostream& operator<< (std::ostream& out, Node& node); 
	friend std::ostream& operator<< (std::ostream& out, Node* node);

};

#endif
