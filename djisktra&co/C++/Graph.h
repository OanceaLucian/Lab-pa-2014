/**
 * Proiectarea Algoritmilor, 2014
 * Lab 8: Drumuri minime
 *
 * @author 	Radu Iacob
 * @email	radu.iacob23@gmail.com
 */
 
#ifndef GRAPH_H
#define GRAPH_H

#include "Utils.h"
#include "Node.h"

class Graph {

	std::vector<Node*> Nodes;
	std::vector< std::vector< std::pair<Node*, int> > > Edges;

public:

	Graph();
	Graph( const std::string& input_graph );

	void clear_graph();
	virtual ~Graph();

	/**
	 * Public API
	 */

	std::vector<Node*>& 				 get_nodes();
	std::vector<Node*>::iterator 		 get_node_iterator();
	void resetNodes();

	std::vector<std::pair<Node*, int> >& get_edges(Node& node);
	Node* get_node( const std::string& city );

	/**
	 * Graph Builder
	 */

	void insert_node(Node* node);
	void insert_edge(Node* node1, Node* node2, int cost);

	uint get_node_count() const;

	/**
	 * IO interface
	 */

	friend std::istream& operator>> (std::istream& in , Graph& node );
	friend std::ostream& operator<< (std::ostream& out, Graph& node ); 

private:

	void init_from_file( const std::string& input_graph );

	void register_node(Node& node);
	std::map< std::string, Node* > nodeDict;

	/**
	 * Internal sanity check
	 */
	void check_node(Node& node) const;

};

#endif
