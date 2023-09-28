#include "../header/simulations.hpp"

#include <iostream>

auto Conway(Grid<Cell> &current_grid, Grid<Cell> &new_grid) -> void{

    for(i32 i = 0; i < current_grid.heigth(); i++) {
        for(i32 j = 0; j < current_grid.width(); j++) {

            i32 num_of_conway_neighbours = 0;

            auto& current_cell = current_grid[{i,j}];

            for(auto &dir : directions3x3 ){
                
                i32 x = i + dir.first;
                i32 y = j + dir.second;
                
                if(x >= 0 and x < current_grid.width() and y >= 0 and y < current_grid.heigth())
                    if(current_grid[{x,y}] == Cell_Type::Conway) num_of_conway_neighbours++;
            }

            if(current_cell == Cell_Type::Conway) {

                if(num_of_conway_neighbours < 2) {
                    // Die

                    new_grid[{i,j}] = Cell_Type::None;
                } 

                if(num_of_conway_neighbours == 2 or num_of_conway_neighbours == 3) {
                    // Stay alive

                    new_grid[{i,j}] = Cell_Type::Conway;
                }

                if(num_of_conway_neighbours > 3) {
                    // Die

                    new_grid[{i,j}] = Cell_Type::None;
                }

                
            } else {
                if(num_of_conway_neighbours == 3) {
                    // Revive

                    new_grid[{i,j}] = Cell_Type::Conway;
                }
            }


        }
    }

}

auto find_pattern_rule90(mini_vec_3 *vec) -> Cell_Type {

    if(vec->first == Cell_Type::None and vec->second == Cell_Type::None and vec->third == Cell_Type::None)
        return Cell_Type::None;

    if(vec->first == Cell_Type::None and vec->second == Cell_Type::None and vec->third == Cell_Type::Rule90)
        return Cell_Type::Rule90;
    
    if(vec->first == Cell_Type::None and vec->second == Cell_Type::Rule90 and vec->third == Cell_Type::None)
        return Cell_Type::None;
    
    if(vec->first == Cell_Type::None and vec->second == Cell_Type::Rule90 and vec->third == Cell_Type::Rule90)
        return Cell_Type::Rule90;

    if(vec->first == Cell_Type::Rule90 and vec->second == Cell_Type::None and vec->third == Cell_Type::None)
        return Cell_Type::Rule90;

    if(vec->first == Cell_Type::Rule90 and vec->second == Cell_Type::None and vec->third == Cell_Type::Rule90)
        return Cell_Type::None;

    if(vec->first == Cell_Type::Rule90 and vec->first == Cell_Type::Rule90 and vec->first == Cell_Type::None)
        return Cell_Type::Rule90;

    if(vec->first == Cell_Type::Rule90 and vec->first == Cell_Type::Rule90 and vec->first == Cell_Type::Rule90)
        return Cell_Type::None;

    return Cell_Type::None;
}

auto Rule90(Grid<Cell> &current_grid, Grid<Cell> &new_grid) -> void {

    static bool seed_set = false;
    if(!seed_set) {
        new_grid[current_grid.width()/2] = Cell_Type::Rule90;
        current_grid[current_grid.width()/2] = Cell_Type::Rule90;
        seed_set = true;
    }

    static i32 row_generation = 0;
    static i32 next_row = row_generation+1;

    // // window of 3
    for(i32 i = 0; i < current_grid.width(); i++) {

        auto index = [&](i32 x) {
            return row_generation*current_grid.width() + (i + x + current_grid.width())%current_grid.width();
        };


        mini_vec_3 vec = {
            current_grid[index(-1)].cell_type,
            current_grid[index(0)].cell_type,
            current_grid[index(1)].cell_type
        };


        Cell_Type new_cell = find_pattern_rule90(&vec);

        new_grid[next_row*new_grid.width() + i%current_grid.width()] = new_cell;
    }

    row_generation = next_row;
    next_row = (next_row + 1) % current_grid.heigth();

}

auto find_pattern_rule30(mini_vec_3 *vec) -> Cell_Type {

    if(vec->first == Cell_Type::None and vec->second == Cell_Type::None and vec->third == Cell_Type::None)
        return Cell_Type::None;

    if(vec->first == Cell_Type::None and vec->second == Cell_Type::None and vec->third == Cell_Type::Rule30)
        return Cell_Type::Rule30;
    
    if(vec->first == Cell_Type::None and vec->second == Cell_Type::Rule30 and vec->third == Cell_Type::None)
        return Cell_Type::Rule30;
    
    if(vec->first == Cell_Type::None and vec->second == Cell_Type::Rule30 and vec->third == Cell_Type::Rule30)
        return Cell_Type::Rule30;

    if(vec->first == Cell_Type::Rule30 and vec->second == Cell_Type::None and vec->third == Cell_Type::None)
        return Cell_Type::Rule30;

    if(vec->first == Cell_Type::Rule30 and vec->second == Cell_Type::None and vec->third == Cell_Type::Rule30)
        return Cell_Type::None;

    if(vec->first == Cell_Type::Rule30 and vec->first == Cell_Type::Rule30 and vec->first == Cell_Type::None)
        return Cell_Type::None;

    if(vec->first == Cell_Type::Rule30 and vec->first == Cell_Type::Rule30 and vec->first == Cell_Type::Rule30)
        return Cell_Type::None;

    return Cell_Type::None;
}


auto Rule30(Grid<Cell> &current_grid, Grid<Cell> &new_grid) -> void {

    static bool seed_set = false;
    if(!seed_set) {
        new_grid[current_grid.width()/2] = Cell_Type::Rule30;
        current_grid[current_grid.width()/2] = Cell_Type::Rule30;
        seed_set = true;
    }

    static i32 row_generation = 0;
    static i32 next_row = row_generation+1;

    // // window of 3
    for(i32 i = 0; i < current_grid.width(); i++) {

        auto index = [&](i32 x) {
            return row_generation*current_grid.width() + (i + x + current_grid.width())%current_grid.width();
        };
        
        mini_vec_3 vec = {
            current_grid[index(-1)].cell_type,
            current_grid[index(0)].cell_type,
            current_grid[index(1)].cell_type
        };


        Cell_Type new_cell = find_pattern_rule30(&vec);

        new_grid[next_row*new_grid.width() + i%current_grid.width()]= new_cell;
    }

    row_generation = next_row;
    next_row = (next_row + 1) % current_grid.heigth(); 

}


auto stone_sand_water(Grid<Cell> &current_grid, Grid<Cell> &new_grid) -> void {


    for(i32 i = 0; i < current_grid.width(); i++) {
        for(i32 j = 0; j < current_grid.heigth(); j++) {

                std::pair<i32, i32> south_west = { i+1,j-1};  
                std::pair<i32, i32> south  = { i+1, j};
                std::pair<i32, i32> south_east = { i+1, j+1};

                Cell& current_cell = current_grid[{i,j}];

                if(current_cell == Cell_Type::Stone) {
                    new_grid[{i,j}] = Cell_Type::Stone;
                    continue;
                }

                // Reached the bottom
                if(south.first >= current_grid.heigth()) continue;

                if(current_cell == Cell_Type::Sand) {
                    

                    

                }


                if(current_cell == Cell_Type::Water) {
                    

                }
        }
    }
}