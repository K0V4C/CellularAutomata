#include "../header/controller.hpp"
#include "../header/window.hpp"
#include "../header/engine.hpp"

#include <iostream>
#include "../header/grid.hpp"

auto main(int argc, char* argv[]) -> int {
    
    Controller::set_resolution(1000, 1000, 20);
    Controller::set_simulation_rule(Controller::Simulation_Rule::Conway);
    Controller::show_grid_line(true);

    Controller::add_main_window(
        new Window(Controller::x_resolution, Controller::y_resolution)
    );
    Controller::add_engine(
        new Engine()
    );

    Controller::run();


    return 0;
}

/*
    TODO
    
    Controller name for the class doesnt make sense also
    Fix error Index out of range if mouse goes of screen

*/