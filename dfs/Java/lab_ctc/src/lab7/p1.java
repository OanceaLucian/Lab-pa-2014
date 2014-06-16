/**
 * Proiectarea Algoritmilor, 2013
 * Lab 7: Aplicatii DFS
 * 
 * @author 	Radu Iacob
 * @email	radu.iacob23@gmail.com
 */

package lab7;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;

import graph.Graph;
import graph.Node;
import graph.Node.Property;

public class p1 {

	/*
		Parcurgere DFS pentru determinarea componentelor tare conexe
		Algoritmul lui Tarjan
	
		Useful API:
		graph.get_edges
		graph.stack
	
		node.visited()
		
		node.level
		node.lowlink
		node.in_stack
		
		optional:
		node.set_property( CTC, indexul_componentei_conexe_curente )
	 */
	static int timp=1;
	static void dfs_ctc( Graph g, Node node, int current_level )
	{
		/*
		 * TODO: Initializeaza level si lowlink
		 */
		System.out.println(node);
		node.level=timp;
		node.lowlink = timp;
		timp++;
		/*
		 * TODO: Adauga nodul in stiva
		 */
		node.set_property(Property.CTC, 1);
		g.stack.push(node);
		node.in_stack=true;
		
		/*
		 * TODO: Parcurgere DF pentru fiecare vecin nevizitat
		 */
			
		for(int i=0;i<g.get_edges(node).size();i++){
			Node u =g.get_edges(node).get(i);
			if(!u.visited()){
				dfs_ctc(g, u, current_level);
				if(node.lowlink>u.lowlink)
					node.lowlink=u.lowlink;
			}
			else{
				if(u.in_stack) {
					if(node.lowlink>u.level){
						node.lowlink=u.level;
					}
				}
			}
		}
		/*
		 * TODO: Salveaza componenta tare conexa curenta
		 */
	  if(node.lowlink==node.level){
		  System.out.println(g.stack);
		  ArrayList<Node> cnodes=new ArrayList<Node>();
		  Node v;
		  do{
			  v=g.stack.pop();
			  v.in_stack=false;
			  cnodes.add(v);
		  } while(node!=v);
		  g.ctc.add(cnodes);
	  }
	}

	/*
	 * Identifica componentele tare conexe din graful primit ca parametru
	 * Complexitate: O( N + M )
	 * N - numarul de noduri
	 * M - numarul de muchii 
	 */
	
	static void StronglyConnectedComponents( Graph g )
	{
		g.reset(); // reseteaza variabilele auxiliare
		
		/*
			TODO: Apeleaza dfs_ctc pentru fiecare nod nevizitat.
		*/
		int current_level=0;
		timp=0;
		 for(int i = 0; i < g.get_nodes().size(); i++){
             Node v = g.get_nodes().get(i);
             if(!v.visited()){
                 dfs_ctc(g, v, current_level);
             }
         }
		
		g.print_ctc(); // afiseaza componentele tare conexe
		return;
	}
		
	/*
		HINT1: Ce tip de graf iti garanteaza ca nu exista cicluri?
		HINT2: In urma compactarii grafului original rezulta tot 
			   un graf orientat.
	*/

	static void bonus( Graph g )
	{
		if( g.ctc.size() == 0 ){
			StronglyConnectedComponents(g);
		}

		/*
			Construim un nou graf 'condensand' componentele tare conexe intr-un singur
			nod.
		*/
	
		Graph cluster = new Graph( Graph.GraphType.DIRECTED );
		for( int i = 0, sz = g.ctc.size(); i < sz; ++i ){
			cluster.insert_node( new Node( i ) );
		}

		ArrayList< Node > all_clusters = cluster.get_nodes();

		for( int i = 0, sz = g.ctc.size(); i < sz; ++i ){
	
			// nodurile care alcatuiesc componenta conexa curenta
			ArrayList< Node > inner_nodes = g.ctc.get(i);
	
			// avoid duplicate edges
	
			HashSet< Integer > connections = new HashSet< Integer >(); 
	
			// pentru fiecare nod..
			for( Node n : inner_nodes )
			{
				ArrayList<Node> edges = g.get_edges( n );
	
				// pentru fiecare muchie..
				for( Node v : edges )
				{
					int idx_ctc = v.get_property( Node.Property.CTC );
			
					if( idx_ctc != i && !connections.contains( idx_ctc ) )
					{
						cluster.insert_edge( all_clusters.get(i), all_clusters.get(idx_ctc) );
						connections.add( idx_ctc );
					}
				}
			}
	
			all_clusters.get(i).sum = inner_nodes.size();
		}
	
		System.out.println( "Graful rezultat in urma compactarii grafului: ");
		System.out.println( cluster );
		
		/*
		 * TODO: Calculeaza numarul maxim de jucatori daca s-ar adauga o legatura artificiala
		 * Complexitate solutie: O( N + M )
		 * N - numarul de noduri din graful comprimat
		 * M - numarul de muchii  
		 */
		
		int ans = -1;
	
		System.out.println("Daca s-ar adauga o legatura artificiala, numarul maxim de jucatori ");
		System.out.println("dintr-un clan ar fi " + ans + "\n");
	}

	final static String PATH = "./res/test01";
	
	public static void main( String... args ) throws FileNotFoundException
	{
		Scanner scanner = new Scanner(new File(PATH));
		int test_count = scanner.nextInt();
		
		while( test_count-- > 0 )
		{	
			Graph g = new Graph( Graph.GraphType.DIRECTED );
			g.readData(scanner);
			System.out.println(g);
			StronglyConnectedComponents(g);
			bonus(g);
		}
		
		scanner.close();
	}
	
}

