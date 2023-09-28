#include "../header/cell.hpp"

#include <memory>
#include "cell.hpp"

Cell::Cell() {
    cell_type = Cell_Type::None;
    rect = nullptr;
}

Cell::Cell(i32 x, i32 y, Cell_Type cell_type) {
    this->cell_type = cell_type;
    this->color = cell_palete[(i32)cell_type];

    rect = new SDL_Rect();
    rect->x = x;
    rect->y = y;
    rect->h = Controller::square_side;
    rect->w = Controller::square_side;
    
}

// copy move and change

//copy
Cell::Cell(const Cell& obj) {
    this->cell_type = obj.cell_type;
    this->color = obj.color;

    this->rect = new SDL_Rect();

    this->rect->h = obj.rect->h;
    this->rect->w = obj.rect->w;
    this->rect->x = obj.rect->x;
    this->rect->y = obj.rect->y;
}

//move
Cell::Cell(Cell&& obj) {
    this->cell_type = obj.cell_type;
    this->color = obj.color;

    this->rect = obj.rect;

    obj.rect = nullptr;
}

//copy
auto Cell::operator=(const Cell& obj) -> Cell& {
    if(this != &obj) {
        delete this->rect;

        this->cell_type = obj.cell_type;
        this->color = obj.color;

        this->rect = new SDL_Rect();

        this->rect->h = obj.rect->h;
        this->rect->w = obj.rect->w;
        this->rect->x = obj.rect->x;
        this->rect->y = obj.rect->y;
    }
    return *this;
}

//move
auto Cell::operator=(Cell&& obj) -> Cell& {
    if(this != &obj) {
        delete this->rect;

        this->cell_type = obj.cell_type;
        this->color = obj.color;

        this->rect = obj.rect;

        obj.rect = nullptr;
    }
    return *this;
}

auto Cell::operator=(Cell_Type cell_type) -> Cell& {
    this->cell_type = cell_type;
    color = cell_palete[(i32)cell_type];
    return *this;
}
