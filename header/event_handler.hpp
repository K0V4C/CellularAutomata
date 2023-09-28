#ifndef EVENT_HANDLER
#define EVENT_HANDLER

#include <SDL2/SDL.h>

#include "types.hpp"

class Window;
class Engine;


// should be singleton
class Event_Handler {
private:

    static bool LEFT_MOUSE_BUTTON_PRESSED;
    static Cell_Type pen;

public:

    static void handle_keyboard(SDL_Event&, Engine*);
    static void handle_mouse(SDL_Event&, Engine*);


};

#endif // EVENT_HANDLER