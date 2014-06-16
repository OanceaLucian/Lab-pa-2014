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
import java.util.Comparator;
import java.util.PriorityQueue;

public class Dijkstra extends MinCost {

	public Dijkstra(Graph graph) {
		super(graph);
	}

	private class NodeComparator implements Comparator<Node> {
		@Override
		public int compare(Node arg0, Node arg1) {
			int dist1 = distance.get(arg0.getId());
			int dist2 = distance.get(arg1.getId());
			return dist1 > dist2 ? 1 : -1;
		}
	}

	/**
	 * Given a graph, with positive cost edges, compute the distance from a
	 * source node to every other node using the Dijkstra algorithm. [3p]
	 * 
	 * Expected Complexity: O( (V+E) * lgV ) ~ O( E * lgV ) where V - num
	 * vertices in graph E - num edges in graph
	 * 
	 * @param source
	 * @return
	 */

	public ArrayList<Integer> computeDistance(Node source) {

		resetDistance();
		int nodeCount = graph.getNodeCount();

		PriorityQueue<Node> pq = new PriorityQueue<Node>(nodeCount,
				new NodeComparator());
		ArrayList<Node> nodes = graph.getNodes();
		ArrayList<Node> parent = new ArrayList<Node>(nodeCount);
		int i;
		for (i = 0; i < nodeCount; i++)
			parent.add(i, null);
		for (i = 0; i < nodeCount; i++) {

			if (graph.existsEdgeBetween(source, nodes.get(i))) {
				distance.set(i, graph.getCostBetween(source, nodes.get(i)));
				pq.add(nodes.get(i));
				parent.set(i, source);
			} else {
				distance.set(i, graph.MAX_VALUE);
				parent.set(i, null);
			}
			distance.set(source.getId(), 0);
		}

		while (!pq.isEmpty()) {

			Node u = pq.poll();

			u.visit();
			ArrayList<Pair<Node, Integer>> neighbors = graph.getEdges(u);
			for (Pair<Node, Integer> g : neighbors) {
				Node v = g.getFirst();
				if (!v.isVisited()
						&& distance.get(v.getId()) > distance.get(u.getId())
								+ graph.getCostBetween(u, v)) {
					distance.set(
							v.getId(),
							distance.get(u.getId())
									+ graph.getCostBetween(u, v));
					parent.set(v.getId(), u);
					if (!pq.contains(v))
						pq.add(v);
					else {
						pq.remove(v);
						distance.set(
								v.getId(),
								distance.get(u.getId())
										+ graph.getCostBetween(u, v));
						pq.add(v);
					}

				}
			}
		}

		return distance;
	}

}
