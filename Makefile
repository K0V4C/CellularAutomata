# Makefile project: Cellular Automata

CCW = g++
CCL = clang++

include_directories = -I external/sdl2/include -I ./header 
link_dirs = -L external/sdl2/lib
link_libs = -l mingw32 -l SDL2main -l SDL2
link_libs_linux = -l SDL2 -l dl
add_sources = $(wildcard ./src/*.cpp)

windows:
	$(CCW) $(include_directories) $(link_dirs) -o cell_engine $(add_sources) $(link_libs)

linux:
	$(CCL) $(include_directories) -o cell_engine $(add_sources) $(link_libs_linux) 
