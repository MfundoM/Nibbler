#include "../includes/Snake.class.hpp"

Snake::Snake(float x, float y, direction dir) :
_direction(dir), _startDir(dir), _move(0), _speed(0.1)
{
  int i = 1;
  SnakeHelper snake(x, y, dir);
  _body.push_back(snake);
  while (i < SNAKE_SIZE) {
    growSnake();
    i++;
  }
  return ;
}

Snake::~Snake(void) {
  return ;
}

void Snake::setDirection(direction dir) {
  _direction = dir;
  _body.front().setDirection(dir);
  return ;
}

void Snake::setStartDirection(direction dir) {
  _startDir = dir;
  return ;
}

bool Snake::moveSnake(double move) {
  t_help::reverse_iterator rbegin = _body.rbegin();
  t_help::reverse_iterator rend = _body.rend();
  t_help::reverse_iterator temp;

  if (_move < _speed) {
    _move += move;
  } else {
    this->setDirection(_startDir);
    while (rbegin != rend) {
      (*rbegin).moveSnake();
      temp = rbegin;
      rbegin++;
      if (rbegin != rend)
        (*temp).setDirection((*rbegin).getDirection());
    }
    _move = 0;
  }
  return (true);
}

void Snake::growSnake(void) {
  SnakeHelper element(_body.back());
  if (element.getDirection() == _UP)
    element.updatePosition(0, 1);
  if (element.getDirection() == _DOWN)
    element.updatePosition(0, -1);
  if (element.getDirection() == _RIGHT)
    element.updatePosition(-1, 0);
  if (element.getDirection() == _LEFT)
    element.updatePosition(1, 0);
  _body.push_back(element);
}

t_help const &Snake::getBody(void) {
  return (_body);
}

SnakeHelper const &Snake::getHead(void) {
  return (_body.front());
}
