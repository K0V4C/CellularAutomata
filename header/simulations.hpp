#ifndef SIMULATIONS
#define SIMULATIONS


#include "cell.hpp"
#include "types.hpp"
#include "grid.hpp"
#include <utility>

const std::pair<i32,i32> directions3x3[] = {
            {-1, -1},  {-1, 0}, {-1, 1},
            { 0, -1},           { 0, 1},
            { 1, -1},  { 1, 0}, { 1, 1}
};
void Conway(Grid<Cell> &current_grid, Grid<Cell> &new_grid);


struct mini_vec_3 {
    Cell_Type first;
    Cell_Type second;
    Cell_Type third;
};

void Rule90(Grid<Cell> &current_grid, Grid<Cell> &new_grid);
void Rule30(Grid<Cell> &current_grid, Grid<Cell> &new_grid);


void stone_sand_water(Grid<Cell> &current_grid, Grid<Cell> &new_grid);


#endif // SIMULATIONS