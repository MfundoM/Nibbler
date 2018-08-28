#include "sfml.class.hpp"

Sfml::Sfml(void) {
  // std::cout << "SFML constructor called" << std::endl;
  return ; }

Sfml::~Sfml(void) {
  // std::cout << "SFML destructor called" << std::endl;
  return ; }

void Sfml::initWindow(int w, int h) {
  _w = w;
  _h = h;
  // create the window
  _win = new sf::RenderWindow(sf::VideoMode((_w * 20) + 18 * 2 , (_h * 20) + 10 * 2 + 30), "NIBBLER");
  if (!_win)
    throw Sfml::SfmlInitError();
  return ;
}

void Sfml::endWindow(void) {
  //Exit the SFML window proparly
  this->_win->close();
  delete this->_win;
  return ;
}

void Sfml::snakeParts(float fx, float fy, type t) {
  int x = static_cast<int>(fx);
  int y = static_cast<int>(fy);

  if (t == _SNAKEHEAD) {
    printSnake(x, y, sf::Color(255, 255, 255));
  } else if (t == _SNAKEBODY) {
    printSnake(x, y, sf::Color(200, 200, 200));
  } else if (t == _FOOD) {
    printFood(x, y);
  }
}

void  Sfml::printSnake(float fx, float fy, const sf::Color &color) {
  int x = static_cast<int>(fx);
  int y = static_cast<int>(fy);

  // define 20*20 rectangle shape
  sf::RectangleShape snake(sf::Vector2f(20, 20));

  // set shape color
  snake.setFillColor(color);
  // set the absolute position of the entity
  // 'entity' can be a sf::Sprite, a sf::Text, a sf::Shape or any other transformable class
  snake.setPosition((x * 20) + 10, 20 + (y * 20));
  this->_win->draw(snake);
  return ;
}

void  Sfml::printFood(float fx, float fy) {
  int x = static_cast<int>(fx);
  int y = static_cast<int>(fy);
  // define circle shape
  sf::CircleShape food(10);

  //set shape Color
  food.setFillColor(sf::Color(255, 0, 0));
  // set the absolute position of the food
  food.setPosition((x * 20) + 10, 20 + (y * 20));

  this->_win->draw(food);
  return ;
}

input Sfml::getInput(void) {
  sf::Event event;
  TMap _inputs;

  _inputs.insert(TPair(sf::Keyboard::P, PAUSE));
  _inputs.insert(TPair(sf::Keyboard::Num1, LIB1));
  _inputs.insert(TPair(sf::Keyboard::Num2, LIB2));
  _inputs.insert(TPair(sf::Keyboard::Num3, LIB3));
  input key;

  key = this->getMove();
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    key = EXIT;
  // while there are pending events...
  while (_win->pollEvent(event)) {
    // check the type of the event...
    switch (event.type) {
      // window closed
      case sf::Event::Closed:
        key = EXIT;
        break;
      // key pressed
      case sf::Event::KeyPressed:
        if (_inputs.find(event.key.code) != _inputs.end())
          key = _inputs[event.key.code];
        break;
      // we don't process other types of events
      default:
        break;
    }
  }
  return (key);
}

input Sfml::getMove(void) const {
  int counter = 0;
  input _inputs[4]; //array of four elements UP, DOWN, LEFT, RIGHT

  for (int i = 0; i < 4; i++)
    _inputs[i] = INVALID;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    _inputs[0] = LEFT;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    _inputs[1] = RIGHT;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    _inputs[2] = UP;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    _inputs[3] = DOWN;
  input key = INVALID;
  for (int i = 0; i < 4; i++) {
    if (_inputs[i] != INVALID) {
      key = _inputs[i];
      counter++;
    }
  }
  if (counter != 1)
    key = INVALID;
  return key;
}

void Sfml::boarder(void) {
  sf::RectangleShape rectangle(sf::Vector2f(_w * 19.6, _h * 19));

  this->_win->clear(sf::Color::Black);
  rectangle.setFillColor(sf::Color(0, 0, 255));
  rectangle.setPosition(29, 40);
  this->_win->draw(rectangle);
  return ;
}

void Sfml::displayWin(void) {
  this->_win->display();
}

void Sfml::printScore(int score) {
  (void)score;
  return ;
}

const char *Sfml::SfmlInitError::what() const throw() {
  return ("SFML initialisation");
}

extern "C" IGraphics * create(void) {
  return (new Sfml());
}
