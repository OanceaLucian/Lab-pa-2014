/**
 * Proiectarea Algoritmilor, 2014
 * Lab 8: Drumuri minime
 *
 * @author 	Radu Iacob
 * @email	radu.iacob23@gmail.com
 */

#include "MinCostAlgo.h"

enum Task{
	ROY_FLOYD,		// Task 1
	DIJKSTRA,		// Task 2
	BELLMAN_FORD	// Task 3 + 4
};

static const std::string dataSet1("./test1.in");
static const std::string dataSet2("./test2.in");

static const std::string startLabel("Bucuresti");
static const std::string endLabel("Paris");

static const std::string currentDataSet = dataSet1;
static const Task  		 currentTask = ROY_FLOYD;

void print_distance_vector( Graph& graph, std::vector<int>& distance )
{
	std::vector< Node* >& nodes = graph.get_nodes();
	std::cout << "Result:\n";
	for( uint i = 0, sz = nodes.size(); i < sz; ++i ){
		std::cout << "< " << nodes[i]->get_city() << " , " << distance[i] << " >\n";
	}
}

int main( int argc, char* argv[] )
{
	Graph graph( currentDataSet );

	Node* source = graph.get_node(startLabel);
	Node* dest   = graph.get_node(endLabel);

	int node_count = graph.get_node_count();

	switch( currentTask )
	{
		case ROY_FLOYD:
		{
			std::cout << "Task1: \n";
			Matrix<int>   costMatrix( node_count, node_count );
			Matrix<Node*> detourMatrix( node_count, node_count );

			RoyFloyd( graph, costMatrix, detourMatrix );
			MinPath( graph, costMatrix, detourMatrix, source, dest );

			break;
		}

		case DIJKSTRA:
		{
			std::cout << "\nTask2: \n";
			std::vector<int> distance = Dijkstra( graph, source );
			print_distance_vector( graph, distance );

			break;
		}

		case BELLMAN_FORD:
		{
			std::cout << "\nTask3: \n";
			std::vector<int> distance = BellmanFord( graph, source );
			print_distance_vector( graph, distance );

			break;
		}

		default:
		{
			break;
		}
	}

	graph.clear_graph();
}
