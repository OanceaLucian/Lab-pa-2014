/**
 * Proiectarea Algoritmilor, 2013
 * Lab 7: Aplicatii DFS
 * 
 * @author 	Radu Iacob
 * @email	radu.iacob23@gmail.com
 */
 
#include "Graph.h"

/*
	Parcurgere DFS pentru determinarea componentelor tare conexe
	Algoritmul lui Tarjan

	Useful API:
	graph.get_edges( *node );
	graph.stack

	node->level
	node->lowlink
	node->in_stack

	optional:
	node->set_property( CTC, indexul_componentei_conexe_curente )
*/

void dfs_ctc( Graph& g, Node* node, int current_level )
{
	/*
	 *	TODO: Initializeaza level si lowlink
	 */

	/*
	 * 	TODO: Adauga nodul in stiva
	 */

	/*
	 * TODO: Parcurgere DF pentru fiecare vecin nevizitat
	 */
	 
	/*
	 * TODO: Salveaza componenta tare conexa curenta
	 */

}

/*
 * 	Identifica componentele tare conexe din graful primit ca parametru
 * 	Complexitate: O( N + M )
 * 	N - numarul de noduri
 * 	M - numarul de muchii 
 */
	 
void StronglyConnectedComponents( Graph& g )
{
	g.reset(); // reseteaza variabilele auxiliare
	
	/*
		TODO: Apeleaza dfs_ctc pentru fiecare nod nevizitat.
	*/

	g.print_ctc(); // afiseaza componentele tare conexe
	return;
}

/*
	HINT1: Ce tip de graf iti garanteaza ca nu exista cicluri?
	HINT2: In urma compactarii grafului original rezulta tot 
		   un graf orientat.
*/

void bonus( Graph& g )
{
	if( g.ctc.size() == 0 ){
		StronglyConnectedComponents(g);
	}

	/*
		Construim un nou graf 'condensand' componentele tare conexe intr-un singur
		nod.
	*/

	Graph cluster;
	for( uint i = 0, sz = g.ctc.size(); i < sz; ++i ){
		cluster.insert_node( new Node( i ) );
	}

	std::vector< Node* >& all_clusters = cluster.get_nodes();
	for( uint i = 0, sz = g.ctc.size(); i < sz; ++i ){

		// nodurile care alcatuiesc componenta conexa curenta
		std::vector< Node* >& inner_nodes = g.ctc[i];

		// avoid duplicate edges
		std::set< int > connections;

		// pentru fiecare nod..
		for( uint j = 0; j < inner_nodes.size(); ++j )
		{
			std::vector< Node* >& edges = g.get_edges( *inner_nodes[j] );

			// pentru fiecare muchie..
			for( uint k = 0; k < edges.size(); ++k )
			{
				uint idx_ctc = edges[k]->get_property( CTC );
		
				if( idx_ctc != i && connections.find( idx_ctc ) == connections.end() )
				{
					cluster.insert_edge( all_clusters[i], all_clusters[idx_ctc] );
					connections.insert( idx_ctc );
				}
			}
		}

		all_clusters[i]->sum = inner_nodes.size();
	}

	std::cout << "Graful comprimat: ";
	std::cout << cluster << "\n";
	
	/*
	 * TODO: Calculeaza numarul maxim de jucatori daca s-ar adauga o legatura artificiala
	 * Complexitate solutie: O( N + M )
	 * N - numarul de noduri din graful comprimat
	 * M - numarul de muchii  
	 */
		
	int ans = -1;

	std::cout << "Daca s-ar adauga o legatura artificiala, numarul maxim de jucatori ";
	std::cout << "dintr-un clan ar fi " << ans << "\n";
}

int main( int argc, char* argv[] )
{
	if( freopen( "test01.in", "r", stdin ) == NULL ) return 1;
	if( freopen( "test01.out", "w", stdout ) == NULL ) return 1;
	
	int nr_teste;
	std::cin >> nr_teste;
	
	while( nr_teste-- )
	{
		Graph g1(DIRECTED);
		std::cin >> g1;
		StronglyConnectedComponents(g1);
		bonus(g1);
	}
	
	return 0;
}
