#ifndef GAME_CLASS_HPP
# define GAME_CLASS_HPP

# include "Header.hh"
# include "IGraphics.hpp"
# include "Library.class.hpp"
# include "Snake.class.hpp"
# include "SnakeHelper.class.hpp"
# include "SnakeFood.class.hpp"

class Game {
public:
  Game(void);
  ~Game(void);
  virtual void initGame(int x, int y);
  virtual void startGame(void);

 private:
  void gameLoop(void);
  void exitKey(input ch);
  void printSnake(void) const;
  collision anyCollision(void);
  void setDirection(input ch);

  lib  _lib;
  Library  _library;
  Snake *_snake;
  int score;

 protected:
  IGraphics *LoadLibrary(lib library);
  void createGame(void) const;
  SnakeFood *food(type f);
  void eat(collision yum, Snake *mouth);
  bool snakeCollision(Snake *crash, SnakeMove const & az);
  input inputManager(void);
  void changeGameState(input ch);
  void changeLibraries(input ch);

   IGraphics *g;
   gameState  _state;
   int _size_X;
   int _size_Y;
   SnakeFood *_food;
   //int _delay;
};

typedef void (Game::*key_fct)(input);

#endif
