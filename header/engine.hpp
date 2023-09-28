#ifndef ENGINE
#define ENGINE

#include "grid.hpp"
#include "cell.hpp"
#include "window.hpp"
#include "simulations.hpp"

class Engine {
private:

    Grid<Cell> output_grid;
    Grid<Cell> compute_grid;

public:

    Engine();

    void draw_background(Color color, Window* gw);

    void draw_grid(Window* gw) const;

    void draw_cells(Window* gw) const;

    void present(Window* gw);

    void  compute();
    void  load();
    
    void change_cell_at_index(i32 index, Cell_Type cell_type);

    ~Engine();

};


#endif // ENGINE