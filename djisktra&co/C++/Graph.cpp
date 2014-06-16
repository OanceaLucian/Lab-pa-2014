/**
 * Proiectarea Algoritmilor, 2014
 * Lab 8: Drumuri minime
 *
 * @author 	Radu Iacob
 * @email	radu.iacob23@gmail.com
 */
 
#include "Graph.h"

Graph::Graph()
{
}

Graph::Graph( const std::string& input_graph )
{
	init_from_file(input_graph);
}

Graph::~Graph()
{
}

void Graph::insert_node(Node* node)
{
	Nodes.push_back(node);
	Edges.push_back(std::vector< std::pair<Node*, int> >());

	register_node(*node);
}

void Graph::insert_edge(Node* node1, Node* node2, int cost)
{
	check_node(*node1);
	check_node(*node2);
	Edges[node1->get_id()].push_back(std::make_pair(node2, cost));
}

std::vector<Node*>& Graph::get_nodes()
{
	return Nodes;
}

std::vector<Node*>::iterator Graph::get_node_iterator(){
	return Nodes.begin();
}

std::vector<std::pair<Node*, int> >& Graph::get_edges(Node& node)
{
	check_node(node);
	return Edges[node.get_id()];
}

void Graph::resetNodes()
{
	for (uint i = 0; i < Nodes.size(); i++)
		Nodes[i]->reset();
}

/**
 * Debug Functionality
 */

std::ostream& operator<< (std::ostream& out, Graph& graph ){

	out << "Print Graph :\n";

	for( uint i = 0; i < graph.Nodes.size(); ++i )
	{
		out << "Edges for " << graph.Nodes[i]->get_city() << " -> ";
		for( uint j = 0, sz = graph.Edges[i].size(); j < sz; ++j ){
			out << graph.Edges[i][j].first->get_city() << "  ";
			out << "(" << graph.Edges[i][j].second << ") || ";
		}
		out << "\n";
	}

	return out;
}


void Graph::init_from_file( const std::string& input_graph )
{
	clear_graph();

	std::fstream in(input_graph.c_str(), std::fstream::in );
	if( !in.good() ){
		throw InvalidQuery("Check input file path!");
	}

	in >> *this;
	in.close();
}

void Graph::clear_graph()
{
	for(uint i = 0, sz = Nodes.size(); i < sz; ++i){
		delete Nodes[i];
	}

	Nodes.clear();
	Edges.clear();
	nodeDict.clear();
}

Node* Graph::get_node( const std::string& city )
{
	return nodeDict[city];
}

void Graph::register_node( Node& node )
{
	nodeDict[ node.get_city() ] = &node;
}

uint Graph::get_node_count() const
{
	return Nodes.size();
}

/**
	 Function to parse a custom graph file
	 for the lab
	  
	 Input Format:
	 N = number of nodes
	 N lines with the city names
	 M = number of edges
	 M lines with Node_i Node_j	costBetweenNodeiNodej	   -- list of edges
*/

std::istream& operator>> (std::istream& in , Graph& graph )
{
	uint _nodes, _edges;
	std::string city;	
	in >> _nodes;

	for (uint i = 0; i < _nodes; ++i) {
		in >> city;
		Node *new_node = new Node(city, i);
		graph.insert_node(new_node);
	}

	in >> _edges;

	int node1, node2, cost;
	for( uint i = 0; i < _edges; ++i ) {
		in >> node1 >> node2 >> cost;
		graph.insert_edge(graph.Nodes[node1], graph.Nodes[node2], cost);
	}

	return in;
}

/**
 * Sanity check
 */

void Graph::check_node( Node& node ) const
{
	uint _id = node.get_id();

	if( _id > get_node_count() || _id < 0 ){
		std::stringstream ss; ss >> _id;
		throw InvalidQuery( "Invalid node id: " + ss.str() );
	}
}

