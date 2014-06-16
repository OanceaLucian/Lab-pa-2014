/**
 * Proiectarea Algoritmilor, 2013
 * Lab 7: Aplicatii DFS
 * 
 * @author 	Radu Iacob
 * @email	radu.iacob23@gmail.com
 */
 
#ifndef GRAPH_H
#define GRAPH_H

#include"Utils.h"
#include"Node.h"

enum GraphType {
	DIRECTED,
	UNDIRECTED
};

class Graph {

	GraphType _type;

	std::vector< Node* > Nodes;
	std::vector< std::vector< Node* > > Edges;
	std::map< std::string, Node* > SocialNetwork;

	void check_node(Node& node) const;

public:

	Graph();
	Graph( GraphType type );
	virtual ~Graph();

	uint node_count() const; 

	void insert_node( Node* node );
	void insert_edge( Node* node1, Node* node2 );
	
	std::vector<Node*>& get_nodes();
	std::vector<Node*>& get_edges( Node& node );

	friend std::istream& operator>> (std::istream& in , Graph& node );
	friend std::ostream& operator<< (std::ostream& out, Graph& node ); 

	/*
		Componente tari conexe
	*/


	std::stack< Node* > stack;
	std::vector< std::vector< Node* > > ctc;

	void print_ctc() const;

	/*
		Componente biconexe
	*/

	std::stack< std::pair< int, int > > edges_stack;
	std::vector< Node* > puncte_de_articulatie;
	std::vector< std::pair< Node*, Node* > > muchii_critice;

	//std::stack< std::pair< Node*, Node* > > comp_biconexa;

	void reset();
};

#endif
