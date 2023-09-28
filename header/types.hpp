#ifndef TYPES_HPP
#define TYPES_HPP

#define i8  char 
#define i16 short int 
#define i32 int
#define i64 long long

#define u8  unsigned char
#define u16 unsigned short
#define u32 unsigned int
#define u64 unsigned long long

struct RGB {
    u8 R;
    u8 G;
    u8 B;
    u8 alpha;
};

enum class Color {
    Red,
    Blue,
    Green,
    Magenta,
    White,
    Black,
    Gray
};

enum class Cell_Type {
    None,
    Conway,
    Rule90,
    Rule30,
    Stone,
    Sand,
    Water
};

const RGB cell_palete[] = {
    {0,100,100,255},
    {0,151,151,255},
    {200,0,200,255},
    {180,180,180,255},
    {183,176,156,255},
    {194,178,128,255},
    {28,163,236,255}
};

const RGB rgb_color_palete[] = {
    {255,0,0,255},
    {0,0,255,255},
    {0,255,0,255},
    {255, 0, 255,255},
    {255,255,255,255},
    {0,0,0,255},
    {0,100,100,255},
};

#endif // TYPES_HPP