/**
 * Proiectarea Algoritmilor, 2014
 * Lab 8: Drumuri minime
 *
 * @author 	Radu Iacob
 * @email	radu.iacob23@gmail.com
 */

#include "MinCostAlgo.h"

/**
 * Given a graph with either positive or negative cost edges,
 * compute the distance from a source node to every other node
 * using the classic BellmanFord implementation.
 *
 * Expected Complexity: O( V * E )
 * where V - num vertices in graph
 * 		 E - num edges in graph
 *
 * throws: InvalidQuery() if graph contains a negative cycle
 */

std::vector<int> BellmanFord( Graph& graph, Node* source )
{
	uint node_count = graph.get_node_count();
	std::vector<int>  distance(node_count, inf);
	std::vector<Node*> nodes = graph.get_nodes();

	

	/**
	 * Task4 [1p]
	 * Detectia ciclurilor negative
	 * Determinati daca exista, respectiv afisati un ciclu de cost negativ.
	 */

	PrintNegativeCycle( graph, distance );

	return distance;
}

void PrintNegativeCycle( Graph& graph, std::vector<int>& distance )
{
	uint node_count = graph.get_node_count();
	std::vector<Node*> nodes = graph.get_nodes();

	
}



