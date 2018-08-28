#include "../includes/SnakeMove.class.hpp"

unsigned int SnakeMove::_i = 0;
SnakeMove::SnakeMove() { return ; }

SnakeMove::SnakeMove(int x, int y, type t, direction dir)  :
_position_X(x), _position_Y(y), _type(t), _direction(dir)
{
  SnakeMove::_i++;
  return ;
}

SnakeMove::~SnakeMove(void) { return ; }

bool SnakeMove::operator==(SnakeMove const &rhs) const {
  if (_i == rhs._i)
    return (true);
  return (false);
}

void SnakeMove::setDirection(direction dir) {
  _direction = dir;
  return ;
}

direction SnakeMove::getDirection(void) const {
  return (_direction);
}

int SnakeMove::getPosition_X(void) const {
  return (_position_X);
}

int SnakeMove::getPosition_Y(void) const {
  return (_position_Y);
}

void SnakeMove::updatePosition(int x, int y) {
  _position_X = _position_X + x;
  _position_Y = _position_Y + y;
  return ;
}

float SnakeMove::getX(void) const {
  return (_position_X);
}

float SnakeMove::getY(void) const {
  return (_position_Y);
}

void SnakeMove::moveSnake(void) {
  if (_direction == _UP)
    _position_Y -= 1;
  else if (_direction == _DOWN)
    _position_Y += 1;
  else if (_direction == _RIGHT)
    _position_X += 1;
  else if (_direction == _LEFT)
    _position_X -= 1;
  return ;
}

void SnakeMove::moveSnake(int size) {
  if (_direction == _UP) {
      if (_position_Y - 1 <= 0)
        _position_Y = size;
      else
        _position_Y -= 1;
  } else if (_direction == _DOWN) {
      if (_position_Y + 1 > size)
        _position_Y = 0;
      else
        _position_Y += 1;
  } else if (_direction == _RIGHT) {
      if (_position_X + 1 > size)
        _position_X = 0;
      else
        _position_X += 1;
  } else if (_direction == _LEFT) {
      if (_position_X - 1 <= 0)
        _position_X = size;
      else
        _position_X -= 1;
  }
  return ;
}

SnakeMove &SnakeMove::operator=(SnakeMove const &rhs) {
  _position_X = rhs._position_X;
  _position_Y = rhs._position_Y;
  _direction = rhs._direction;
  _type = rhs._type;
  return (*this);
}
