#include "SDL.class.hpp"

SDLibrary::SDLibrary() {
    // std::cout << "SDL constructor called" << std::endl;
}

SDLibrary::~SDLibrary(){
    // std::cout << "SDL destructor called" << std::endl;
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}

void    SDLibrary::initWindow(int w, int h) {
  _w = w;
  _h = h;
  //Init everything so we have everything
	SDL_Init(SDL_INIT_EVERYTHING);

  //Show the window with these settings and apply a renderer to it
	//The renderer is responsible for all graphics being displayed
	this->window = SDL_CreateWindow("Nibbler", 100, 100, (w * 20) + 18 * 2, (h * 20) + 10 * 2 + 30, SDL_WINDOW_SHOWN);
  SDL_SetWindowBordered(this->window, SDL_TRUE);
  this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
}

void    SDLibrary::endWindow(void) {
  SDL_DestroyWindow(this->window);
	SDL_Quit();
}

void    SDLibrary::snakeParts(float fx, float fy, type t) {
    int x = static_cast<int>(fx);
    int y = static_cast<int>(fy);
    // (void)x;
    // (void)y;
    // (void)t;
     if (t == _SNAKEHEAD) {
       printSnake(x, y, SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255));
     } else if (t == _SNAKEBODY) {
        printSnake(x, y, SDL_SetRenderDrawColor(this->renderer, 200, 200, 200, 200));
    } else if (t == _FOOD) {
        //TODO food function
        printFood(x, y);
    }
}

void    SDLibrary::printSnake(float fx, float fy, int color) {
    int x = static_cast<int>(fx);
    int y = static_cast<int>(fy);
    (void)color;
    SDL_Rect snake;

    snake.w = 20;
    snake.h = 20;

    snake.y = (y * 20) + 20;
    snake.x = (x * 20) + 10;

    SDL_RenderFillRects(this->renderer, &snake, 4);
}

input   SDLibrary::getInput(void){
  // input ch = INVALID;
  if (SDL_PollEvent(&this->event)) {
      if (this->event.key.keysym.sym == SDLK_ESCAPE) {
            exit(0);
      }
      if (this->event.type == SDL_KEYDOWN) {
      //Then check for the key being pressed and change direction accordingly
          if (this->event.key.keysym.scancode == SDL_SCANCODE_UP) {
              return(UP);
          } else if (this->event.key.keysym.scancode == SDL_SCANCODE_LEFT) {
              return(LEFT);
          } else if (this->event.key.keysym.scancode == SDL_SCANCODE_DOWN) {
              return(DOWN);
          } else if (this->event.key.keysym.scancode == SDL_SCANCODE_RIGHT) {
              return(RIGHT);
          } else if (this->event.key.keysym.scancode == SDL_SCANCODE_1) {
            return(LIB1);
          } else if (this->event.key.keysym.scancode == SDL_SCANCODE_2) {
            return(LIB2);
          } else if (this->event.key.keysym.scancode == SDL_SCANCODE_3) {
            return(LIB3);
          } else if (this->event.key.keysym.scancode == SDL_SCANCODE_P) {
            return(PAUSE);
          }
      }
  }
  return (INVALID);
}

void SDLibrary::boarder(void){
    SDL_Rect MyRect;
    MyRect.w = (_w * 19.6);
    MyRect.h = (_h * 19);
    MyRect.x = 29;
    MyRect.y = 40;
    SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 0);
    SDL_RenderFillRect(this->renderer, &MyRect);
}

void SDLibrary::printFood(float fx, float fy) {
  int x = static_cast<int>(fx);
  int y = static_cast<int>(fy);
  SDL_Rect food;
  food.w = 20;
  food.h = 20;
  food.x = (x * 20) + 10;
  food.y = (y * 20) + 20;
  SDL_SetRenderDrawColor(this->renderer, 255, 0, 0, 0);
	SDL_RenderFillRect(this->renderer, &food);
}

void SDLibrary::displayWin(void){
    SDL_RenderPresent(this->renderer);
    SDL_SetRenderDrawColor(this->renderer, 0, 0, 255, 0);
    SDL_RenderClear(this->renderer);
}

void SDLibrary::printScore(int score){
    (void)score;
}

extern "C" IGraphics * create(void) {
  return (new SDLibrary());
}
