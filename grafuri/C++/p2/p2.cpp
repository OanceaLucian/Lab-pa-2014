#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

#include "Cell.h"

using namespace std;

stack<Cell*> cell_stack;

vector<Cell*> read_file_input(string file_name) {
    map<string, Cell*> cells;
    vector<Cell*> final_cells;
    
    ifstream in("date.in");
    string formula;
    
    while (getline(in, formula)) {
        stringstream formulastream(formula);
        string token;
        formulastream >> token;
        
        Cell* cell = NULL;
        if (cells.find(token) == cells.end()) {
            cell = new Cell(token);
            cells.insert(make_pair(token, cell));
            
            final_cells.push_back(cell);
        } else {
            cell = cells[token];
        }
        
        while (formulastream >> token) {
            if (token.length() == 2) {
                Cell* dependentCell = new Cell(token);
                if (cells.find(token) == cells.end()) {            
                    cells.insert(make_pair(token, dependentCell));
                    
                    final_cells.push_back(dependentCell);
                }
                  
                cells[token]->add_dependent_cell(cell);
            }
        }
    }
    
    return final_cells;
}

void DFS(Cell* cell) {
    //TODO: Implementati DFS. La finalul parcurgerii unei celule, adaugati
	// celula in cell_stack.
	
}

int main() {
    vector<Cell*> cells = read_file_input("date.in");
    
    //TODO: Afisati parcurgerea celulelor.

    return 0;
}
