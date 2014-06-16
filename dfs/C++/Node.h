/**
 * Proiectarea Algoritmilor, 2013
 * Lab 7: Aplicatii DFS
 * 
 * @author 	Radu Iacob
 * @email	radu.iacob23@gmail.com
 */
 
#ifndef NODE_H
#define NODE_H

#include "Utils.h"

enum Property{
	CTC			// Strongly Connected Component
};

class Node{

	std::string _name;
	uint _id;
	
	/*
		Generic property field
	*/

	std::map< Property, int > _prop;

public:

	Node( std::string name, uint id );
	Node( uint id );
	
	const std::string& get_name() const;
	const uint get_id() const;

	bool visited();

	int get_property( Property p );
	void set_property( Property p, int value );

	friend std::istream& operator>> (std::istream& in , Node& node );
	friend std::ostream& operator<< (std::ostream& out, Node& node ); 
	friend std::ostream& operator<< (std::ostream& out, Node* node );

	static const int UNSET = -1;

	/*
		DF traversal
	*/

	// timpul de initializare in parcurgerea DF
	int level;		

	/*
		Componente tare conexe
	*/
	
	// cel mai mic level al unui nod accesibil din nodul curent 
	int lowlink;

	// nodul se afla in stack
	bool in_stack;

	// optional - indexul componentei tare conexe
	int ctc_index;
	// optional
	int sum;


};

#endif
