#ifndef SNAKEFOOD_CLASS_HPP
# define SNAKEFOOD_CLASS_HPP

# include "Header.hh"
# include "SnakeMove.class.hpp"

class SnakeFood : public SnakeMove {
public:
  SnakeFood(int x, int y);
  ~SnakeFood(void);
};

#endif
