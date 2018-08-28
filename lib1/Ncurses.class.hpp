#ifndef NCURSES_CLASS_HPP
# define NCURSES_CLASS_HPP

# include "../includes/IGraphics.hpp"
# include "../includes/Header.hh"

class Ncurses : public IGraphics {
public:
  Ncurses(void);
  ~Ncurses(void);

	void initWindow(int w, int h);
	void endWindow(void);
	void snakeParts(float x, float y, type t);
	input getInput(void);
	void boarder(void);
	void displayWin(void);
  void printScore(int score);

private:
  WINDOW* _win;
  int     _x;
  int     _y;
  const char *_snakePart;
  const char *_food;
  char _boarder;
  static std::map<int, input> _input;
  static std::map<int, input> createInput(void);
};
extern "C" IGraphics * create(void);

#endif
