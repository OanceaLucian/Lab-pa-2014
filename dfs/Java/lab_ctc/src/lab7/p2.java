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
import graph.Pair;

public class p2 {

	/*
	 * Afiseaza componentele biconexe, salvate in stiva
	 */
	
	static void print_biconex_component( Graph g, Node n1, Node n2 )
	{
		System.out.println("Componenta biconexa: ");
		
		HashSet< Node > comp = new HashSet< Node >();
		
		Pair< Node, Node > aux;
		
		do
		{
			aux = g.edge_stack.pop();
			
			comp.add( aux.getFirst() );
			comp.add( aux.getSecond() );
			
		}while( aux.getFirst() != n1 || aux.getSecond() != n2 );
		
		System.out.println( comp );
	}
	
	/*
	 * Useful API:
	 * 
	 * graph.edge_stack
	 * graph.muchii_critice
	 * graph.puncte_de_articulatie
	 * graph.get_edges
	 * 
	 * node.level
	 * node.lowlink
	 * node.in_stack
	 * 
	 */
  static int timp;
	static void dfs_biconex( Graph g, Node node, int current_level, int father_id )
	{
		ArrayList< Node > childs = new ArrayList< Node >();
		
		/*
		 * TODO: Initializati level si lowlink
		 */
		 node.level=timp;
		 node.lowlink=timp;
		 timp++;
		/*
		 * TODO: Parcurgere recursiva a copiilor nevizitati
		 */
		
		 for(int i=0;i<g.get_edges(node).size();i++){
			 Node u=g.get_edges(node).get(i);
			 if(u.get_id()==father_id) continue;
			 if(!u.visited()){
				 childs.add(u);
				 g.edge_stack.push(new Pair<Node, Node>(node, u));
				 dfs_biconex(g, u, current_level, node.get_id());
				 if(node.lowlink>u.lowlink)
					 node.lowlink=u.lowlink;
				 if(u.lowlink>node.level)
					 g.muchii_critice.add(new Pair<Node, Node>(node, u));
				 if(u.lowlink >= node.level){
	                    print_biconex_component(g, node, u);
	                }
			 }
			 else {
				 if(node.lowlink>u.level)
					 node.lowlink=u.level;
			 }
		 }
		 
		/*
		 * TODO: Identifica daca nodul este punct de articulatie
		 */
		 if(father_id == -1 ) {
			 if(childs.size()>=2) g.puncte_de_articulatie.add(node);
		 }
		 else{
			 boolean ok=false;
           for(int i=0;i<childs.size();i++){
        	   Node u=childs.get(i);
        	   if(u.lowlink>=node.level)
        		   ok=true;
        	   if(ok) g.puncte_de_articulatie.add(u);
           }
        	   
		 }
		
	}
	
	/*
	 * Descompune graful in componente biconexe
	 *
	 * Useful API:
	 * 
	 * g.get_nodes()
	 * node.visited()
	 */

	static void ComponenteBiconexe( Graph g )
	{
		g.reset();
		
		/*
		 * TODO: Parcurgere df pentru identificarea componentelor biconexe
		 */
		timp=0;int llevel=0;
		for(int i = 0; i < g.get_nodes().size(); i++){
            Node v = g.get_nodes().get(i);
            if(!v.visited()){
                dfs_biconex(g, v, llevel, -1);
            }
    }

		System.out.println("\nPuncte. de articulatie: \n" + g.puncte_de_articulatie );
		System.out.println("\nMuchii critice: \n" + g.muchii_critice );
	}
	
	final static String PATH = "./res/test02";
	
	public static void main( String... args ) throws FileNotFoundException
	{
		Scanner scanner = new Scanner(new File(PATH));
		int test_count = scanner.nextInt();
		
		while( test_count-- > 0 )
		{
			Graph g = new Graph( Graph.GraphType.UNDIRECTED );	
			g.readData( scanner );
			System.out.println(g);
			ComponenteBiconexe(g);
		}
		
		scanner.close();
	}
	
	
	
}

