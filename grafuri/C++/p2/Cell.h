#ifndef __CELL_H__
#define __CELL_H__

/**
 * 
 * Reprezentarea unei celule dintr-un spreadsheet.
 * 
 * @author Claudia Cardei
 *
 */

#include <fstream>
#include <string>
#include <vector>

using namespace std;

/**
 * Culorile ce le poate avea o celula in timpul unei parcurgeti DFS.
 */
enum Color {
  WHITE,
  GRAY,
  BLACK
};

class Cell {
 private:
    /**
	 * Pozitia celulei in cadrul spreadsheet-ului.
	 */
    string position;
    
    /*
	 * Celulele care depind de celula curenta.
	 */
    vector<Cell*> dependent_cells;
    
    /**
	 * Atribute folositoare in cadrul DFS-ului.
	 */
	Color color;
	int init_time;
	int finish_time;
	
 public:
    Cell();
    Cell(string position);
    ~Cell();
    
    void add_dependent_cell(Cell* cell);
    Cell* get_dependent_cell_at(int index);
    int get_dependent_cells_size();
    
    void set_color(Color color);
    Color get_color();
    void set_init_time(int time);
    int get_init_time();
    void set_finish_time(int time);
    int get_finish_time();
    
    friend ostream& operator<< (ostream&, const Cell&);
};

#endif 
