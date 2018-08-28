#ifndef SNAKE_CLASS_HPP
# define SNAKE_CLASS_HPP

# include "Header.hh"
# include "SnakeHelper.class.hpp"

typedef std::list<SnakeHelper> t_help;
class  Snake {
public:
  Snake(float x, float y, direction dir);
  ~Snake(void);

  void setDirection(direction dir);
  void setStartDirection(direction dir);
  bool moveSnake(double move);
  void growSnake(void);
  t_help const &getBody(void);
  SnakeHelper const &getHead(void);

private:
  t_help _body;
  direction _direction;
  direction _startDir;
  double _move;
  double _speed;
};

#endif
