#ifndef SNAKEMOVE_CLASS_HPP
# define SNAKEMOVE_CLASS_HPP

# include "Header.hh"

class SnakeMove {
public:
  SnakeMove();
  SnakeMove(int x, int y, type t, direction dir);
  ~SnakeMove(void);

  bool operator==(SnakeMove const &rhs) const;
  void setDirection(direction dir);
  direction getDirection(void) const;
  int getPosition_X(void) const;
  int getPosition_Y(void) const;
  void updatePosition(int x, int y);
  float getX(void) const;
  float getY(void) const;
  void moveSnake(void);
  void moveSnake(int size);

private:
  SnakeMove &operator=(SnakeMove const &rhs);
  int _position_X;
  int _position_Y;
  t_type _type;
  direction _direction;
  static unsigned int _i;
};

#endif
