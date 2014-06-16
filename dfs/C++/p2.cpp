/**
 * Proiectarea Algoritmilor, 2013
 * Lab 7: Aplicatii DFS
 * 
 * @author 	Radu Iacob
 * @email	radu.iacob23@gmail.com
 */
 
#include "Graph.h"

/*
	Afiseza elementele din componenta biconexa curenta
*/

void print_biconex_component( Graph& g, int nod1, int nod2 )
{
	std::cout << "Componenta biconexa (id-uri): ";

	std::set< int > comp;
	std::pair< int, int > aux;

	do{
		aux = g.edges_stack.top(); 
		g.edges_stack.pop();
		
		comp.insert(aux.first);
		comp.insert(aux.second);
		
	} while( nod1 != aux.first || nod2 != aux.second );

	for( std::set<int>::iterator it = comp.begin(); it != comp.end(); ++it )
		std::cout << *it << " ";	
	std::cout << "\n";
}

/*
 * Note: O singura parcurgere este suficienta pentru obtinerea
 * 	 tuturor informatiilor cerute. Daca va este mai usor, puteti sa
 *       rezolvati in mai multe etape.
 *
 * Useful API:
 * 
 * graph.edges_stack
 * graph.muchii_critice
 * graph.puncte_de_articulatie
 * graph.get_edges
 * 
 * node->level
 * node->lowlink
 * 
 */

void dfs_biconex( Graph& g, Node* node, int current_level, int father_id )
{
	/*
	 * TODO: Initializati level si lowlink
	 */

	/*
	 * TODO: Parcurgere recursiva a copiilor nevizitati
	 */
	
	/*
	 * TODO: Identifica daca nodul este punct de articulatie
	 */
}

/*
 * Descompune graful in componente biconexe
 *
 * Useful API:
 * 
 * graph.get_nodes()
 * node.visited()
 */
	 
void ComponenteBiconexe( Graph& g )
{
	g.reset();

	std::cout << "Puncte de articulatie:\n";
	std::cout << g.puncte_de_articulatie;

	std::cout << "Muchii critice:\n";
	std::cout << g.muchii_critice;

}

int main( int argc, char* argv[] )
{
	if( freopen( "test02.in", "r", stdin ) == NULL ) return 1;
	if( freopen( "test02.out", "w", stdout ) == NULL ) return 1;
	
	int nr_teste;
	std::cin >> nr_teste;
	
	while( nr_teste-- )
	{
		Graph g2( UNDIRECTED );
		std::cin >> g2;
		ComponenteBiconexe( g2 );
	}

	return 0;
}
