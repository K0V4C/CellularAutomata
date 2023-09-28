#include "../header/window.hpp"
#include "../header/controller.hpp"
#include "../header/simulations.hpp"

#include <iostream>

Window::Window(i32 x_resolution, i32 y_resoltion) {

    window = SDL_CreateWindow("Cellular Automaton Controller", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED
                                , x_resolution, y_resoltion, SDL_WINDOW_ALLOW_HIGHDPI);

    if(NULL == window) {
        std::cout << "Could not create a window: " << SDL_GetError() << "\n";
    }

    renderer = SDL_CreateRenderer(window, -1, 0);

    if(NULL == renderer) {
        std::cout << "Could not create a renderer: " << SDL_GetError() << "\n";
    }
}


Window::~Window(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}
