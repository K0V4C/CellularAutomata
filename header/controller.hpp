#ifndef CONTROLLER
#define CONTROLLER

#include "types.hpp"
class Window;
class Engine;

class Controller {
public:
    enum class State {
        Running,
        Simulating, 
        Finished
    };

    enum class Simulation_Rule{
        Conway,
        Rule90,
        Rule30,
        SSW,
        Custom
    };
private:
    // Singleton class
    Controller(Controller&) = delete;
    void operator=(Controller&) = delete;
    Controller();

    static Controller *instance;

    // What Controller owns
    Window* main_window;
    Engine* engine;

    State Controller_state;
    Simulation_Rule rule;

public:

    static i32 FPS;
    static i32 frame_delay;

    static void set_fps(i32 fps);

    static i32 x_resolution, y_resolution;
    static i32 x_squares, y_squares, square_side;

    static bool grid_lines;

    static void set_resolution(i32 x_resolution, i32 y_resolution, i32 square_side);

    static void add_main_window(Window* gw);

    static void add_engine(Engine* engine);
    
    static void set_simulation_rule(Controller::Simulation_Rule);
    static Controller::Simulation_Rule get_simulation_rule();

    static void show_grid_line(bool flag);

    static void set_state(Controller::State);
    static Controller::State get_state();

    inline void render_screen();
    inline void handle_envent();
    inline void simulate();

    static Controller& get_instance();

    static void run();

    ~Controller();
};

#endif // CONTROLLER