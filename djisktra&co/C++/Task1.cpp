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
 * compute the minimum path cost between every node as well
 * as the 'next-hop' node for every such node
 *
 * Expected complexity: O( V^3 )
 * where V - num vertices in graph
 *
 *
 * Input:
 * Graph graph		 	-- Graf orientat (reprezentand trasee posibile prin Europa)
 *
 * Output:
 * Matrix costMatrix 	-- M[i][j] costul minim al unui path de la nodul i la nodul j
 * Matrix detourMatrix 	-- M[i][j] reprez primul nod din path-ul de cost minim de la nodul i la nodul j
 *						   ex: pt path-ul (i, k, j) valoarea M[i][j] = k
 *
 * 	Don't forget to initialize the solution matrixes
 *
 * Hint:
 * For debugging, you can easily print the cost matrix to any output stream
 * 	std::cout << cost << "\n"
 * ..or the graph
 *  std::cout << graph << "\n"
 *
 */

void RoyFloyd( Graph& graph,
			   Matrix<int>& cost, Matrix<Node*>& detour )
{
	uint node_count = graph.get_node_count();
	std::vector< Node* >& nodes = graph.get_nodes();

	cost.set_all(inf);
	detour.set_all(NULL);

	
}

Node* pivot_sanity_check( Graph graph, Matrix<Node*>& detour, Node* node1, Node* node2 )
{
	int id1 = node1->get_id();
	int id2 = node2->get_id();

	if( id1 == id2 ){
		std::string msg("Path from node ");
		msg += id1 + " to itself requested.";
		throw InvalidQuery(msg);
	}

	Node* pivot = detour.get_elem(id1,id2);
	if( pivot == NULL ){
		std::string msg("No path connects");
		msg += node1->get_city() + " to " + node2->get_city();
		msg += "\n";
		throw InvalidQuery(msg);
	}

	if( pivot->is_visited() ){
		throw InvalidQuery("Cycle Detected!");
	}

	return pivot;
}

void MinPath( Graph& graph, Matrix<int>& cost, Matrix<Node*>& detour,
			  Node* node1, Node* node2 )
{
	std::cout << "Best route between ";
	std::cout << node1->get_city() << " and ";
	std::cout << node2->get_city() << "\n";

	graph.resetNodes();

	//Hint: You may use pivot_sanity_check to retrieve
	//		the "next" node on the path from node1 to node2

	

	std::cout << "Total Cost: " << cost.get_elem( node1->get_id(), node2->get_id() ) << "\n";
}
