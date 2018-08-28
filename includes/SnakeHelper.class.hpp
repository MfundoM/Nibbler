#ifndef SNAKEHELPER_CLASS_HPP
# define SNAKEHELPER_CLASS_HPP

# include "Header.hh"
# include "SnakeMove.class.hpp"

class SnakeHelper : public SnakeMove {
public:
  SnakeHelper(float x, float y, direction dir);
  ~SnakeHelper(void);
};

#endif
