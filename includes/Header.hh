#ifndef HEADER_HH
# define HEADER_HH

# define SNAKE_SIZE 4
# define DEFAULT_LIB NCURSES

# include <iostream>
# include <curses.h>
# include <sstream>
# include <map>
# include <vector>
# include <list>
# include <dlfcn.h>
# include <ctime>
# include <unistd.h>
# include <cmath>
# include <exception>
# include <string>
# include <ctype.h>


enum input {
  INVALID = -1,
  RIGHT,
  UP,
  LEFT,
  DOWN,
  EXIT,
  LIB1,
  LIB2,
  LIB3,
  PAUSE
};

enum direction {
  _RIGHT = 0,
  _UP,
  _LEFT,
  _DOWN
};

typedef enum type {
	_SNAKEBODY = 0,
	_SNAKEHEAD,
	_FOOD
}				t_type;

enum lib {
  NCURSES = 0, //lib1
  SFML,//TODO lib2
  SDL//TODO lib3
};

enum collision {
  NONE = 0,
  WALL,
  FOOD,
  SNAKE
};

enum gameState {
  _RUNNING = 1,
  _PAUSE,
  _LOSE,
  _WIN,
  _EXIT
};

#endif
