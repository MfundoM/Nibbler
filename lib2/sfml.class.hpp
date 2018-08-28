#ifndef SFML_CLASS_HPP
# define SFML_CLASS_HPP

# include "../includes/Header.hh"
# include "../includes/IGraphics.hpp"
# include <SFML/Window.hpp>
# include <SFML/Graphics.hpp>

class Sfml : public IGraphics {
public:
  Sfml(void);
  ~Sfml(void);

  class SfmlInitError : std::exception {
  public:
    const char *what() const throw();
  };

  void initWindow(int w, int h);
	void endWindow(void);
	void snakeParts(float x, float y, type t);
	input getInput(void);
	void boarder(void);
	void displayWin(void);
  void printScore(int score);

private:
  void  printSnake(float x, float y, const sf::Color &color);
  void  printFood(float x, float y);
  input getMove(void) const;

  sf::RenderWindow *_win;
  sf::Font _font;
  int _w;
  int _h;
};
typedef std::map<int, input> TMap;
typedef std::pair<int, input> TPair;

extern "C" IGraphics * create(void);

#endif
