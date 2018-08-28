#pragma once

# include "../includes/Header.hh"
# include "../includes/IGraphics.hpp"
# include <SDL2/SDL.h>

class   SDLibrary : public IGraphics {
    public:
        SDLibrary();
        ~SDLibrary();

        void initWindow(int w, int h);
        void endWindow(void);
        void snakeParts(float x, float y, type t);
        input getInput(void);
        void boarder(void);
        void displayWin(void);
        void printScore(int score);

    private:
        void printSnake(float x, float y, int color);
        void printFood(float x, float y);
    	  SDL_Window* window;
	      SDL_Renderer* renderer;
	      SDL_Event event;
        int _w;
        int _h;
};

extern "C" IGraphics * create(void);
