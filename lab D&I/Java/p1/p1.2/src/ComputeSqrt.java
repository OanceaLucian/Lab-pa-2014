/**
 * Proiectarea Algoritmilor, 2014
 * Lab 1: Divide et Impera
 * Task 1.2: Se da un numar natural n. Scrieti un algoritm de complexitate O(log n)
 * care sa calculeze sqrt(n)
 *
 * @author 	Mihai Bivol, Alex Olteanu
 * @email	alexandru.olteanu@cs.pub.ro
 */

public class ComputeSqrt {

	public static void main(String[] args) {

		/*TODO Calculati radicalul pentru trei valori alese de voi,
		 * folosind functia sqrt definita mai jos. Cel putin o valoare
		 * trebuie sa fie subunitara. Precizia va fi de 0.001
		 *
		 * Decideti care va fi valoarea upper folosita.
		 * Hint: ce se intampla cand x<1?
		 */

		

	}

	/**
	 * Function that says if two values are equal within precision
	 */
	private static boolean equal(double x, double y, double precision)
	{
		return Math.abs(x - y) < precision;
	}

	/**
	 * Iterative function to compute sqrt
	 */
	private static double sqrt(double x, double lower, double upper, double precision)
	{
		// TODO Cautati intre lower si upper o valoare care ridicata
		// la patrat sa dea x.
		// La calcularea pozitiei de mijloc folositi
		//       double m = lower + (upper - lower) / 2;
		// pentru a evita overflow la adunarea pe double
		// Folositi functia equal pentru a verifica cu aproximare egalitatea
		
		return 0;
	}
}
