package grafp2;

import java.util.LinkedList;
import java.util.Queue;

public class Treasure {

	public static void main(String[] args) {
		int n = 10;
		int[][] costs = new int[n][n];

		char[][] map = { 
				{ '.', '.', '.', '#', '.', '.', '.', '.' },
				{ '#', '.', '.', '#', '.', '.', '#', '.' },
				{ '.', '#', '#', '.', 'P', '.', '.', '#' },
				{ '.', '.', '#', '.', '#', '.', '#', '.' },
				{ '.', '.', '.', '.', '.', '.', '.', '.' },
				{ '.', '.', '.', '.', '.', '.', '.', '.' },
				{ '#', '#', '#', '.', '.', '.', '#', '#' },
				{ '.', '.', 'P', '.', '.', '.', '.', '.' } };

		
		Queue<Guard> qguard = new LinkedList<Guard>();
		for (int i = 0; i < n-2; i++)
			for (int j = 0; j < n-2; j++)
				if (map[i][j] == '#')
					costs[i+1][j+1] = -2;
				else if (map[i][j] == '.')
					costs[i+1][j+1] = -1;
				else if (map[i][j] == 'P') {
					costs[i+1][j+1] = 0;
					qguard.add(new Guard(i+1, j+1));
				}		
		for(int i=0;i<n;i++){
		costs[0][i]=-2;
		costs[i][0]=-2;
		costs[n-1][i]=-2;
		costs[i][n-1]=-2;
		
		
		}
		
		
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				System.out.print(costs[i][j] + "\t");
			System.out.println();
		}

		int rx[] = { 0, 1, 0, -1 };
		int ry[] = { 1, 0, -1, 0 };
		Queue<Guard> qroad = new LinkedList<Guard>();

		while (qguard.isEmpty()==false) {
			qroad.add(qguard.peek());
			qguard.remove();
			while (qroad.isEmpty()==false) {
				Guard now = qroad.peek();
				qroad.remove();
				int newi, newj;
				for (int k = 0; k < 4; k++) {
					newi = now.i + rx[k];
					newj = now.j + ry[k];
					if ( costs[newi][newj] != -2 && 
							(costs[newi][newj] > costs[now.i][now.j] + 1 || (costs[newi][newj] == -1))) {
						costs[newi][newj] = costs[now.i][now.j] + 1;
						qroad.add(new Guard(newi, newj));
					}
				}

			}

		}
		System.out.println("Solutia");
		for (int i = 1; i < n-1; i++) {
			for (int j = 1; j < n-1; j++)
				System.out.print(costs[i][j] + "\t");
			System.out.println();
		}

	}

}
