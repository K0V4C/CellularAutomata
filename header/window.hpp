#ifndef WINDOW
#define WINDOW

#include <SDL2/SDL.h>
#include "types.hpp"

#include "grid.hpp"
#include "cell.hpp"

class I_Cell;
class Conway_Cell;

class Window{
private:

    SDL_Window *window;
    SDL_Renderer *renderer;

    friend class Controller;
    friend class Engine;

public:

    Window(i32 x_resolution, i32 y_resolution);

    ~Window();
};

#endif
