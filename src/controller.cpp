#include "../header/controller.hpp"
#include "../header/event_handler.hpp"
#include "../header/window.hpp"
#include "../header/engine.hpp"

#include <SDL2/SDL.h>

#include <iostream>

Controller* Controller::instance = nullptr;

i32 Controller::x_resolution = -1;
i32 Controller::y_resolution = -1;
i32 Controller::square_side = -1;
i32 Controller::x_squares = -1;
i32 Controller::y_squares = -1;
i32 Controller::FPS = 200;
i32 Controller::frame_delay = 1000 / FPS;
bool Controller::grid_lines = true;

auto Controller::set_resolution(i32 x_resolution, i32 y_resolution, i32 square_side) -> void {

    Controller::square_side = square_side;

    Controller::x_squares = x_resolution / square_side;
    Controller::y_squares = y_resolution / square_side;

    Controller::x_resolution= Controller::x_squares * square_side;
    Controller::y_resolution = Controller::y_squares * square_side; 

    std::cout << x_squares << " | " << y_squares << std::endl;

}

Controller::Controller(): Controller_state(Controller::State::Running) {
        SDL_Init(SDL_INIT_EVERYTHING);
}


// Run body of the controller ///////
auto Controller::run() -> void {
    Controller& Controller = Controller::get_instance();

    u32 frame_start;
    i32 frame_time;

    frame_start = SDL_GetTicks();

    while(Controller::get_state() == Controller::State::Running
            or Controller::get_state() == Controller::State::Simulating) {
        
        frame_start = SDL_GetTicks();

        Controller.handle_envent();
        Controller.simulate();
        Controller.render_screen();


        frame_time = SDL_GetTicks() - frame_start;
        if(frame_delay > frame_time) {
            // SDL_Delay(frame_delay - frame_time);
        }
    }
}

auto Controller::set_fps(i32 fps) -> void {
    Controller::get_instance().FPS = fps;
    Controller::get_instance().frame_delay = 1000/fps;
}

auto Controller::render_screen() -> void {
    engine->draw_background(Color::Blue, main_window);
    engine->draw_cells(main_window);

    if(Controller::grid_lines)
        engine->draw_grid(main_window);
    engine->present(main_window);

}

auto Controller::handle_envent() -> void {
    SDL_Event event;
    if(SDL_PollEvent(&event)){
        Event_Handler::handle_keyboard(event, engine);
        Event_Handler::handle_mouse(event, engine);
    }
}

auto Controller::simulate() -> void {
    // Simulatiion
    if(Controller::get_state() == Controller::State::Simulating) {
        engine->compute();
        engine->load();
    }
}

// Getter and setters
auto Controller::set_state(Controller::State state) -> void {
    Controller::get_instance().Controller_state = state;
}

auto Controller::get_state() -> Controller::State {
    return Controller::get_instance().Controller_state;
}

auto Controller::set_simulation_rule(Controller::Simulation_Rule rule) -> void{
    Controller::get_instance().rule = rule;
}

auto Controller::get_simulation_rule() -> Controller::Simulation_Rule {
    return Controller::get_instance().rule;
}

auto Controller::add_main_window(Window *gw) -> void {
    Controller::get_instance().main_window = gw;
}

auto Controller::add_engine(Engine* engine) -> void {
    Controller::get_instance().engine = engine;
}

auto Controller::get_instance() -> Controller& {

    if(instance) return *instance;

    instance = new Controller();
    return *instance;
    
}

auto Controller::show_grid_line(bool flag) -> void {

    Controller::get_instance().grid_lines = flag;

}

Controller::~Controller() {
    delete main_window;
    delete engine;
    SDL_Quit();
}