import java.util.List;
import java.util.Stack;

/**
 * Clasa principala unde veti implementa sortarea topologica.
 * 
 * @author Claudia Cardei
 * 
 */
public class p2 {

	public static Stack<Cell> cellStack = new Stack<Cell>();

	public static void DFS(Cell cell) {
		// TODO: Implementati DFS. La finalul parcurgerii unei celule, adaugati
		// celula in cellStack.
		int t = 0;
		List<Cell> dependent = cell.getDependentCells();
		cell.setColor(Cell.Color.GRAY);
		cell.setInitTime(t);
		++t;
		for(int i = 0; i < dependent.size(); i++) {
			if (dependent.get(i).getColor() == Cell.Color.WHITE) {
				DFS(dependent.get(i));
			}
		}
		// celula in cellStack.
		cell.setColor(Cell.Color.BLACK);
		cell.setFinishTime(t);
		cellStack.add(cell);
	}

	public static void main(String[] args) {
		Reader reader = new Reader("date.in");
		List<Cell> cells = reader.parse();

		for(int i = 0; i < cells.size(); i++) {
			if (cells.get(i).getColor() == Cell.Color.WHITE)
				DFS(cells.get(i));
		}
		
		
		while(!cellStack.isEmpty()) {
			System.out.println(cellStack.pop().toString());
		}

	}
}
