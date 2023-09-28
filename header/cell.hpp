#ifndef CELL
#define CELL

#include "types.hpp"
#include <SDL2/SDL.h>
#include "controller.hpp"

#include <iostream>

struct Cell {

    Cell_Type cell_type;
    SDL_Rect *rect = nullptr;
    RGB color;

    Cell();
    Cell(i32 x, i32 y, Cell_Type cell_type);

    friend std::ostream& operator<< (std::ostream& os, const Cell& obj) {
        os << (i32)obj.cell_type;
        return os;
    }

    Cell(const Cell& obj);
    Cell(Cell&& obj);

    Cell& operator=(const Cell& obj);
    Cell& operator=(Cell&& obj);

    Cell& operator=(Cell_Type cell_type);

    friend bool operator==(const Cell& obj, Cell_Type cell_type) {
        return obj.cell_type == cell_type;
    }
    friend bool operator==(const Cell& left, const Cell& right) {
        return left.cell_type == right.cell_type;
    }

};

#endif