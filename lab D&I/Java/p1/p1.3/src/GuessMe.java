/**
 * Proiectarea Algoritmilor, 2014
 * Lab 1: Divide et Impera
 * Task 1.3: Se da o structura de date in care este stocata o variabila necunoscuta (denumita unknown).
 * Gasiti valoarea necunoscuta folosind metoda isInBounds.
 *
 * @author 	Mihai Bivol, Alex Olteanu
 * @email	alexandru.olteanu@cs.pub.ro
 */

public class GuessMe {

	private int unknown;
	private static final int MAX_VALUE = 424242; // Magic constant is magic

	public static void main(String[] args) {
		GuessMe g = new GuessMe();

		g.setUnknown(1);
		if (g.guess()==1) System.out.println("Corect!");
		else System.out.println("Gresit :(");

		g.setUnknown(10);
		if (g.guess()==10) System.out.println("Corect!");
		else System.out.println("Gresit :(");

		g.setUnknown(15);
		if (g.guess()==15) System.out.println("Corect!");
		else System.out.println("Gresit :(");

		g.setUnknown(42);
		if (g.guess()==42) System.out.println("Corect!");
		else System.out.println("Gresit :(");

	}

	boolean isInBounds(int x) {
		return x <= unknown;
	}

	private void setUnknown(int u) {
		unknown = u;
	}

	private int guess() {
		int lower = 0;
		int upper = MAX_VALUE;
		int res = 0;

		/*TODO Folosind metoda isInBounds cautati binar
		 * cea mai mare valoare pentru care isInBounds intoarce true.
		 * Vom denumi acea valoare unknown. Se stie ca isInBounds
		 * intoarce true de la 0 la unknown si false pentru numere mai mari
		 * decat unknown:
		 *
		 * Exemplu, unknown = 4
		 *    _________
		 * f:          |_______
		 * x: 0 1 2 3 4 5 6 7 8
		 *
		 * Remember! (lower + upper) / 2 is bad!
		 */
		
		return res;
	}
}
