#include "Cell.h"

Cell::Cell() {
    position = "";
    color = WHITE;
    init_time = finish_time = 0;
}

Cell::Cell(string position) {
    this->position = position;
    
    color = WHITE;
    init_time = finish_time = 0;
}

Cell::~Cell() {
    for (unsigned int i = 0; i < dependent_cells.size(); i++) {
        delete dependent_cells[i];
    }
}

void Cell::add_dependent_cell(Cell* cell) {
    dependent_cells.push_back(cell);
}

Cell* Cell::get_dependent_cell_at(int index) {
    return dependent_cells[index];
}

int Cell::get_dependent_cells_size() {
    return dependent_cells.size();
}

void Cell::set_color(Color color) {
    this->color = color;
}

Color Cell::get_color() {
    return color;
}

void Cell::set_init_time(int time) {
    init_time = time;
}

int Cell::get_init_time() {
    return init_time;
}


void Cell::set_finish_time(int time) {
    finish_time = time;
}


int Cell::get_finish_time() {
    return finish_time;
}

ostream& operator<< (ostream& out, const Cell& cell)
{
    out << cell.position;
    return out;
}

