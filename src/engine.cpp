#include "../header/engine.hpp"
#include "engine.hpp"


Engine::Engine() {
    //Used to store mid phase states
    compute_grid = Grid<Cell>(Controller::x_squares, Controller::y_squares);

    // Used to calcuate and visualise
    output_grid = Grid<Cell>(Controller::x_squares, Controller::y_squares);

    for(i32 i = 0; i < output_grid.size(); i++) {
        i32 x_pos = (i % Controller::x_squares) * Controller::square_side;
        i32 y_pos = (i / Controller::x_squares) * Controller::square_side;

        output_grid[i] = *(new Cell(x_pos, y_pos, Cell_Type::None));
        compute_grid[i] = *(new Cell(x_pos, y_pos, Cell_Type::None));

    }
}

auto Engine::draw_background(Color color, Window* gw) -> void {
    RGB colors = rgb_color_palete[(i32)color];

    SDL_SetRenderDrawColor(gw->renderer,
                            colors.R,
                            colors.G,
                            colors.B,
                            colors.alpha);

    // Gives clear canvas
    SDL_RenderClear(gw->renderer);
}


auto Engine::draw_grid(Window* gw) const -> void {

    RGB colors = rgb_color_palete[(i32)Color::Black];

    SDL_SetRenderDrawColor(gw->renderer,
                            colors.R,
                            colors.G,
                            colors.B,
                            colors.alpha);

    // Draw vertical lines
    for(i32 i = 1; i < Controller::x_squares; i++) {
        SDL_RenderDrawLine(gw->renderer, i*Controller::square_side, 0, i*Controller::square_side, Controller::y_resolution);
    }

    
    // Draw horizontal lines
    for(i32 i = 1; i < Controller::y_squares; i++) {
        SDL_RenderDrawLine(gw->renderer, 0, i*Controller::square_side, Controller::x_resolution, i*Controller::square_side);
    }
}

auto Engine::draw_cells(Window* gw) const -> void {

    for(auto &cell : output_grid) {
        
        RGB colors = cell->color;

        SDL_SetRenderDrawColor(gw->renderer,
                            colors.R,
                            colors.G,
                            colors.B,
                            colors.alpha);

        SDL_RenderFillRect(gw->renderer, cell->rect);

    }

}

auto Engine::present(Window* gw) -> void {
    SDL_RenderPresent(gw->renderer);
}


// TODO change this
auto Engine::change_cell_at_index(i32 index, Cell_Type cell_type) -> void {
    output_grid[index] = cell_type;
}

auto Engine::compute() -> void {


    if(Controller::get_simulation_rule() == Controller::Simulation_Rule::Conway) {
        Conway(output_grid, compute_grid);
    }

    if(Controller::get_simulation_rule() == Controller::Simulation_Rule::Rule90) {
        Rule90(output_grid, compute_grid);
    }

    if(Controller::get_simulation_rule() == Controller::Simulation_Rule::Rule30) {
        Rule30(output_grid, compute_grid);
    }

    if(Controller::get_simulation_rule() == Controller::Simulation_Rule::SSW) {
        stone_sand_water(output_grid, compute_grid);
    }
}

auto Engine::load() -> void {
    output_grid = compute_grid;
}


Engine::~Engine(){}
