#include "../header/event_handler.hpp"
#include "../header/controller.hpp"
#include "../header/engine.hpp"

#include <iostream>

#include <SDL2/SDL.h>

bool Event_Handler::LEFT_MOUSE_BUTTON_PRESSED = false;
Cell_Type Event_Handler::pen = Cell_Type::None;

auto Event_Handler::handle_keyboard(SDL_Event& event, Engine* engine) -> void {

    if(SDL_QUIT == event.type) {
        Controller::set_state(Controller::State::Finished);
    }

    // TODO: make this not wait mouse press
    if(SDL_KEYDOWN == event.type) {
        if(SDLK_r == event.key.keysym.sym) {

            if(Controller::get_state() == Controller::State::Simulating) {
                Controller::set_fps(60);
                Controller::set_state(Controller::State::Running);
            } else {
                Controller::set_fps(200);
                Controller::set_state(Controller::State::Simulating);
            }
        }

        // TODO: make this work
        if(SDLK_q == event.key.keysym.sym) {
            Controller::set_state(Controller::State::Finished);
        }
    }

    if(Controller::get_simulation_rule() == Controller::Simulation_Rule::Conway) {
        Event_Handler::pen = Cell_Type::Conway;
    } 

    // Stone Sand Water
    if(Controller::get_simulation_rule() == Controller::Simulation_Rule::SSW) {
        if(SDL_KEYDOWN == event.type) {
            if(SDLK_1 == event.key.keysym.sym) {
                std::cout << "Pen selected: Stone\n";
                Event_Handler::pen = Cell_Type::Stone;
            }

            if(SDLK_2 == event.key.keysym.sym) {
                std::cout << "Pen selected: Sand\n";
                Event_Handler::pen = Cell_Type::Sand;
            }

            if(SDLK_3 == event.key.keysym.sym) {
                std::cout << "Pen selected: Water\n";
                Event_Handler::pen = Cell_Type::Water;
            }
        }

    }


}

/*
    TODO List:
    
    Change gamewindow class so it doesnt use stupid operator[]
    Add modoularity to code
    Maybe add operator [] for engine so we can get rid off change_cell_at_index

*/

auto Event_Handler::handle_mouse(SDL_Event& event, Engine* engine) -> void {

    i32 mouse_x_pos, mouse_y_pos;
    SDL_GetMouseState(&mouse_x_pos, &mouse_y_pos);

    i32 matrix_index = (mouse_x_pos / Controller::square_side) + (mouse_y_pos / Controller::square_side) * Controller::x_squares;

    if(Controller::get_simulation_rule() == Controller::Simulation_Rule::Conway ) {

        // State machine to check if mouse is held down
        if(LEFT_MOUSE_BUTTON_PRESSED) {
            engine->change_cell_at_index(matrix_index, Event_Handler::pen);
        }

        if(SDL_MOUSEBUTTONDOWN == event.type ) {
            if(SDL_BUTTON_LEFT == event.button.button) {
                LEFT_MOUSE_BUTTON_PRESSED = true;

                engine->change_cell_at_index(matrix_index, Event_Handler::pen);
            }

        }

        if(SDL_MOUSEBUTTONUP == event.type) {
            if(SDL_BUTTON_LEFT == event.button.button) {
                LEFT_MOUSE_BUTTON_PRESSED = false;
            }
        }
        
    }

    // Rule90 and Rule30 doesnt need handling of the mouse

    // Stone Sand and Water
    if(Controller::get_simulation_rule() == Controller::Simulation_Rule::SSW) {

         // State machine to check if mouse is held down
        if(LEFT_MOUSE_BUTTON_PRESSED) {
            engine->change_cell_at_index(matrix_index,Event_Handler::pen);
        }

        if(SDL_MOUSEBUTTONDOWN == event.type ) {
            if(SDL_BUTTON_LEFT == event.button.button) {
                LEFT_MOUSE_BUTTON_PRESSED = true;

                engine->change_cell_at_index(matrix_index, Event_Handler::pen);
            }

        }

        if(SDL_MOUSEBUTTONUP == event.type) {
            if(SDL_BUTTON_LEFT == event.button.button) {
                LEFT_MOUSE_BUTTON_PRESSED = false;
            }
        }


    }

}