/**
 * Proiectarea Algoritmilor, 2014
 * Lab 8: Drumuri minime
 *
 * @author 	Radu Iacob
 * @email	radu.iacob23@gmail.com
 */

#ifndef MINCOSTALGO_H_
#define MINCOSTALGO_H_

#include "Graph.h"
#include "Matrix.hpp"

/**
 * Task1
 */

void RoyFloyd( Graph& graph, Matrix<int>& costMatrix, Matrix<Node*>& detourMatrix );
void MinPath( Graph& graph, Matrix<int>& costMatrix, Matrix<Node*>& detourMatrix,
			  Node* node1, Node* node2 );

/**
 * Task2
 */

std::vector<int> Dijkstra( Graph& graph, Node* source );

/**
 * Task3
 */

std::vector<int> BellmanFord( Graph& graph, Node* source );

/**
 * Task4
 */

// Prerequisites: BellmanFord
void PrintNegativeCycle( Graph& graph, std::vector<int>& distance );


#endif /* MINCOSTALGO_H_ */
