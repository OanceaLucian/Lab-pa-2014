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

public class BellmanFord extends MinCost {

	public BellmanFord(Graph graph) {
		super(graph);
	}

	/**
	 * Given a graph with either positive or negative cost edges, compute the
	 * distance from a source node to every other node using the classic
	 * BellmanFord implementation. [2p]
	 * 
	 * Expected Complexity: O( V * E ) where V - num vertices in graph E - num
	 * edges in graph
	 * 
	 * @param source
	 * @return
	 */

	public ArrayList<Integer> computeDistance(Node source) {

		int nodeCount = graph.getNodeCount();
		ArrayList<Node> parent = new ArrayList<Node>(nodeCount);
		for (int i = 0; i < nodeCount; i++)
			parent.add(i, null);
		ArrayList<Node> nodes = graph.getNodes();
		for (int i = 0; i < nodes.size(); i++) {
			if (graph
					.existsEdgeBetween(nodes.get(source.getId()), nodes.get(i))) {
				distance.set(
						i,
						graph.getCostBetween(nodes.get(source.getId()),
								nodes.get(i)));
				parent.set(i, source);
			} else {
				distance.set(i, graph.MAX_VALUE);
				parent.set(i, null);
			}
		}
		distance.set(source.getId(), 0);

		for (int k = 1; k < nodes.size() - 1; k++) {
			for (int i = 0; i < nodes.size(); i++) {
				for (int j = 0; j < nodes.size(); j++) {
					Node u = nodes.get(i);
					Node v = nodes.get(j);
					if (graph.existsEdgeBetween(u, v)) {
						int w = graph.getCostBetween(u, v);
						if (distance.get(v.getId()) > distance.get(u.getId())
								+ w) {
							distance.set(v.getId(), distance.get(u.getId()) + w);
							parent.set(v.getId(), u);
						}
					}
				}
			}
		}

		checkNegativeCycle();

		return distance;
	}

	/**
	 * Check if there exists a negative cycle and print such a cycle if it
	 * exists. [1p]
	 */

	public void checkNegativeCycle() {

	}

}
