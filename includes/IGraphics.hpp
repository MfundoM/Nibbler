#ifndef IGRAPHICS_HPP
# define IGRAPHICS_HPP

# include "Header.hh"
# include "SnakeMove.class.hpp"

class IGraphics{
public:
	virtual ~IGraphics(void) {}
	virtual void initWindow(int w, int h) = 0;
	virtual void endWindow(void) = 0;
	virtual void snakeParts(float x, float y, type t) = 0;
	virtual input getInput(void) = 0;
	virtual void boarder(void) = 0;
	virtual void displayWin(void) = 0;
	virtual void printScore(int score) = 0;
};

#endif
