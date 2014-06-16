/**
 * Proiectarea Algoritmilor, 2013
 * Lab 7: Aplicatii DFS
 * 
 * @author 	Radu Iacob
 * @email	radu.iacob23@gmail.com
 */
 
#include "Graph.h"

Graph::Graph() : _type(DIRECTED)
{

}

Graph::Graph( GraphType type ) : _type(type)
{

}

Graph::~Graph()
{
	for( uint i = 0, sz = node_count(); i < sz; ++i ){
		delete Nodes[i];
	}
}

uint Graph::node_count() const{
	return Nodes.size();
}

void Graph::insert_node( Node* node )
{
	Nodes.push_back( node );
	Edges.push_back( std::vector< Node* >() );
	SocialNetwork[ node->get_name() ] = Nodes[ Nodes.size() - 1 ];
}

void Graph::insert_edge( Node* node1, Node* node2 )
{
	check_node( *node1 );
	Edges[ node1->get_id() ].push_back( node2 );
}

std::vector<Node*>& Graph::get_nodes(){
	return Nodes;
}

std::vector<Node*>& Graph::get_edges( Node& node )
{
	check_node( node );
	return Edges[ node.get_id() ];
}

void Graph::reset()
{
	for( uint i = 0, sz = Nodes.size(); i < sz; ++i )
	{
		Nodes[i]->level   = Node::UNSET;
		Nodes[i]->lowlink = Node::UNSET;
	}

	while( !stack.empty() ) stack.pop();
	ctc.clear();

	puncte_de_articulatie.clear();
	muchii_critice.clear();
}

void Graph::check_node( Node& node ) const
{
	uint _id = node.get_id();
		
	if( _id > node_count() || _id < 0 ){
		std::stringstream ss; ss >> _id;
		throw InvalidQuery( "Invalid node id: " + ss.str() );
	}
}

void Graph::print_ctc() const
{
	std::cout << "Strongly Connected Components:\n";

	for( uint i = 0, sz1 = ctc.size(); i < sz1; ++i )
	{
		for( uint j = 0, sz2 = ctc[i].size() ; j < sz2; ++j )
		{
			std::cout << *ctc[i][j] << " ";
		}
		std::cout << "\n";
	}

	std::cout << "\n";
}

std::ostream& operator<< (std::ostream& out, Graph& graph ){

	std::cout << "Print Graph :\n";

	for( uint i = 0; i < graph.Nodes.size(); ++i )
	{
		std::cout << "Edges for node " << *graph.Nodes[i] << " -> ";
		for( uint j = 0, sz = graph.Edges[i].size(); j < sz; ++j ){
			std::cout << *graph.Edges[i][j] << " , ";
		}
		std::cout << "\n";
	}

	return out;
}

/*
	Input Format:

	N M
	
	Node1 Node2 Node3.. NodeN  -- list with every node
	
	Nodei Nodej				   -- list of edges
	...

	where 
	N = Number of Nodes
	M = Number of Edges
*/

std::istream& operator>> (std::istream& in , Graph& graph )
{
	uint _nodes, _edges;
	in >> _nodes >> _edges;

	std::string name1, name2;
	for( uint i = 0; i < _nodes; ++i )	
	{
		in >> name1;
		Node *new_node = new Node( name1, i );
		graph.insert_node( new_node );
	}

	for( uint i = 0; i < _edges; ++i )
	{
		in >> name1 >> name2;
		graph.insert_edge( graph.SocialNetwork[name1], 
				   graph.SocialNetwork[name2] );
		
		if( graph._type == UNDIRECTED )
		{
			graph.insert_edge( graph.SocialNetwork[name2],
		   			   graph.SocialNetwork[name1] );
		}
	}

	return in;
}
