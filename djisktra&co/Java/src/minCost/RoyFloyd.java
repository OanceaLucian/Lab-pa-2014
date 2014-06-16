/**
 * Proiectarea Algoritmilor, 2014
 * Lab 8: Drumuri minime
 *
 * @author 	Radu Iacob
 * @email	radu.iacob23@gmail.com
 */

package minCost;

import graph.Graph;
import graph.Node;
import graph.Pair;

import java.util.ArrayList;
import java.util.GregorianCalendar;

public class RoyFloyd {

	Integer cost[][];
	Node detour[][];

	public static final int INF = Integer.MAX_VALUE;

	public RoyFloyd(int nodeCount) {
		cost = new Integer[nodeCount][nodeCount];
		detour = new Node[nodeCount][nodeCount];
	}

	/**
	 * Given a graph with either positive or negative cost edges, compute the
	 * minimum path cost between every node as well as the 'next-hop' node for
	 * every such node. [3p]
	 * 
	 * Expected complexity: O( V^3 ) where V - num vertices in graph
	 * 
	 * Hint (useful API): dumpCostMatrix(); graph.getEdges(node)
	 * 
	 * Don't forget to initialize the cost and detour matrixes!
	 * 
	 * @param graph
	 */

	public void computeRoyFloyd(Graph graph) {
		resetCostMatrix();
		resetDetourMatrix();

		ArrayList<Node> nodes = graph.getNodes();
		int nodeCount = graph.getNodeCount();

		for (int i = 0; i < nodeCount; i++) {
			for (int j = 0; j < nodeCount; j++) {
				this.cost[i][j] = graph.getCostBetween(nodes.get(i),
						nodes.get(j));
				this.detour[i][j] = null;
			}
		}
		for (int k = 0; k < nodeCount; k++) {
			for (int i = 0; i < nodeCount; i++) {
				for (int j = 0; j < nodeCount; j++) {
					if (this.cost[i][j] > this.cost[i][k] + this.cost[k][j]) {
						this.cost[i][j] = this.cost[i][k] + this.cost[k][j];
						this.detour[i][j] = nodes.get(k);
					}
				}
			}
		}

		for (int i = 0; i < nodeCount - 1; i++) {
            for (int j = i + 1 ; j < nodeCount; j++) {
                PrintMinPath(graph, nodes.get(i), nodes.get(j));
            }
        }
        //dumpCostMatrix();
	
	}

	/**
	 * Print the path with minimum cost between two given nodes, based on the
	 * detour matrix computed previously [1p]
	 * 
	 * @param node1
	 * @param node2
	 */

	public void PrintMinPath(Graph graph, Node node1, Node node2) {
		System.out.println("Total cost: " + cost[node1.getId()][node2.getId()]);
		System.out.print("Best route between ");
		System.out.println(node1.getCity() + " and " + node2.getCity());

		int i = node1.getId();
		int j = node2.getId();
		//Hint: You may use PivotSanityCheck to retrieve
		//      the "next" node on the path from node1 to node2
		
		 ArrayList<Node> nodes = graph.getNodes();
        
         
         if (this.detour[i][j] == null) {
             return;
         }
         
         ArrayList<Node> path = new ArrayList<Node>();
         path.add(node1);
         Node k = this.detour[i][j];
         while (k != null) {
             path.add(k);
             k = this.detour[i][k.getId()];
         }
         path.add(node2);
         
         for (int t = path.size()-1; t >= 0; t--)
                 System.out.print(nodes.get(path.get(t).getId()).getCity() + " ");

		System.out.println("Total cost: " + cost[node1.getId()][node2.getId()]);
	System.out.println();
	}

	/**
	 * 
	 * @param node1
	 * @param node2
	 * @return
	 */

	private Node PivotSanityCheck(Graph graph, Node node1, Node node2) {
		int id1 = node1.getId();
		int id2 = node2.getId();

		if (id1 == id2) {
			throw new RuntimeException("Path from node " + node1.getCity()
					+ " to itself requested");
		}

		Node pivot = detour[id1][id2];
		if (pivot == null) {
			throw new RuntimeException("No path connects " + node1.getCity()
					+ " to " + node2.getCity());
		}

		if (pivot.isVisited()) {
			throw new RuntimeException("Cycle Detected");
		}
		pivot.visit();

		return pivot;
	}

	public void dumpCostMatrix() {
		for (int i = 0; i < cost.length; ++i) {
			for (int j = 0; j < cost[i].length; ++j) {
				System.out.print(cost[i][j] + " ");
			}
			System.out.print("\n");
		}

		System.out.println("\n");
	}

	public void resetCostMatrix() {
		for (int i = 0; i < cost.length; ++i) {
			for (int j = 0; j < cost[i].length; ++j) {
				cost[i][j] = INF;
			}
		}
	}

	public void resetDetourMatrix() {
		for (int i = 0; i < detour.length; ++i) {
			for (int j = 0; j < detour[i].length; ++j) {
				detour[i][j] = null;
			}
		}
	}

}
