/**
 * Proiectarea Algoritmilor, 2014
 * Lab 8: Drumuri minime
 *
 * @author 	Radu Iacob
 * @email	radu.iacob23@gmail.com
 */

#include "MinCostAlgo.h"


class node_cmp
{
public:

	node_cmp( std::vector<int>& dist )
		:	dist(dist)
	{
	}

	bool operator() ( Node* A, Node* B ){
		return dist[ A->get_id() ] > dist[ B->get_id() ];
	}

private:
	std::vector<int>& dist;
};

typedef std::priority_queue< Node*, std::vector<Node*>, node_cmp > node_priority_queue;

/**
 * Given a directed graph, with positive cost edges, compute the distance
 * from a source node to every other node using the Dijkstra algorithm.
 *
 * Expected Complexity: O( (V+E) * lgV ) ~ O( E * lgV )
 * where V - num vertices in graph
 * 		 E - num edges in graph
 *
 * Useful API and hints:
 * graph.get_edges( node& ) -> return a vector with out-going edges from the given node
 */

std::vector<int> Dijkstra( Graph& graph, Node* source )
{
	std::cout << "Apply Dijkstra for node " << source->get_city() << "\n";

	uint node_count = graph.get_node_count();

	std::vector< int > distance( node_count, inf );
	graph.resetNodes();

	node_cmp comp(distance);		// node comparator, requires distance vector
	node_priority_queue pq( comp ); // priority queue, requires custom comparator

	

	return distance;
}

