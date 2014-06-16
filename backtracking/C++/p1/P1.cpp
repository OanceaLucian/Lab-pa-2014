/**
 * Proiectarea Algoritmilor, 2014
 * Lab 4: Backtracking si optimizari
 * Task 1: Sudoku - Simple Backtracking
 *
 * @author 	Stefan Ruseti
 * @email	stefan.ruseti@gmail.com
 */
#include <iostream>
#include <fstream>

using namespace std;

int bktCounter = 0;
int solutionCounter = 0;
int grid[9][9];

/**
 * Intoarce true daca cifra adaugata la pozitia (row, column)
 * nu contrazice cifrele deja completate
 *
 */
bool isValid(int grid[9][9], int row, int column) {
    for (int i = 0; i < 9; i++)
        if (i != column && grid[row][i] != 0 && grid[row][i] == grid[row][column])
            return false;
    for (int i = 0; i < 9; i++)
        if (i != row && grid[i][column] != 0 && grid[i][column] == grid[row][column])
            return false;
    for (int i = (row / 3) * 3; i < (row / 3 + 1) * 3; i++)
        for (int j = (column / 3) * 3; j < (column / 3 + 1) * 3; j++)
            if ((i != row || j != column) &&
                    grid[i][j] != 0 && grid[i][j] == grid[row][column])
                return false;

    return true;
}

void printGrid(int grid[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (grid[i][j] == 0) cout << " ";
            else cout << grid[i][j];
            cout << " ";
        }
        cout<<endl;
    }
    cout<<endl;
}

/**
 * Implementarea backtracking-ului simplu
 *
 */
void doBKT(int grid[9][9], int row, int column) {

    bktCounter++; // incrementam numarul total de intrari in recursivitate

    // TODO 2: Implementarea algoritmului de backtracking simplu
    // TODO 3: Afisarea tuturor solutiilor gasite
    // TODO 4: Incrementarea variabilei solutionCounter pentru fiecare solutie
    if(row==9 && column==0)
    {
        printGrid(grid);
        solutionCounter++;
        return;
    }


    if(grid[row][column]==0)
     for(int i=1;i<10;i++)
      {
        grid[row][column]=i;
        if(isValid(grid,row,column))
        {
            if(column<8)
            doBKT(grid,row,column+1);
            else doBKT(grid,row+1,column-8);
        }
        grid[row][column]=0;
    }
    else
        if(column<8)
        doBKT(grid,row,column+1);
        else doBKT(grid,row+1,column-8);

}

int main() {
    ifstream fin("sudoku.in");

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            fin>>grid[i][j];
    bktCounter = 0;
    solutionCounter = 0;
    doBKT(grid, 0, 0);
    std::cout<<std::endl<<std::endl;



    cout<<"Numar de intrari in recursivitare :"<<bktCounter<<endl;
    cout<<"Numar de solutii gasite: "<<solutionCounter<<endl;
    return 0;
}



