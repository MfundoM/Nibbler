#include "SDL.class.hpp"

SDLibrary::SDLibrary() : window(NULL), renderer(NULL), _i(RIGHT) {
}

SDLibrary::~SDLibrary(){}

void    SDLibrary::initWindow(int w, int h){
        // SDL_CreateWindowAndRenderer(w, h, 0, &window, &renderer)
        this->_this = w;
        this->_that = h;
}

        void SDLibrary::endWindow(void){
        
            if (renderer) {
                SDL_DestroyRenderer(renderer);
            }

            if (window) {
                SDL_DestroyWindow(window);
            }
            SDL_Quit();
        }

        void SDLibrary::snakeParts(float x, float y, type t){
            (void)x;
            (void)y;
            (void)t;
        }

        input SDLibrary::getInput(void){
            return _i;
        }
        void SDLibrary::boarder(void){}

void SDLibrary::displayWin(void){
    if (SDL_Init(SDL_INIT_VIDEO) == 0) {
    // SDL_Window* window = NULL;
    // SDL_Renderer* renderer = NULL;

        if (SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer) == 0) {
            SDL_bool done = SDL_FALSE;

            while (!done) {
                SDL_Event event;

                SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
                SDL_RenderClear(renderer);

                SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
                SDL_RenderDrawLine(renderer, 320, 200, 300, 240);
                SDL_RenderDrawLine(renderer, 300, 240, 340, 240);
                SDL_RenderDrawLine(renderer, 340, 240, 320, 200);
                SDL_RenderPresent(renderer);

                while (SDL_PollEvent(&event)) {
                    if (event.type == SDL_QUIT) {
                        done = SDL_TRUE;
                    }
                }
            }
        }
    }
}

void SDLibrary::printScore(int score){
    (void)score;
}

extern "C" IGraphics * create(void) {
  return (new SDLibrary());
}


// ################################################################################
//      COOOOOOOOOMMMMMMMMMEEEEEEENNNNNNNNNNTTTTTTTTTTSSSSSSSSSSSSSS
// ################################################################################
/*
// SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
                // SDL_RenderClear(renderer);
                // SDL_bool done = SDL_FALSE;

                // SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
                // SDL_RenderDrawLine(renderer, 320, 200, 300, 240);
                // SDL_RenderDrawLine(renderer, 300, 240, 340, 240);
                // SDL_RenderDrawLine(renderer, 340, 240, 320, 200);
                // SDL_RenderPresent(renderer);
                // SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
                // // SDL_RenderClear(renderer);
                
                // while (!done) {
                //     while (SDL_PollEvent(&event)) {
                //         SDL_SetRenderDrawColor(renderer, 105, 105, 105, 255);
                //         SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	            //         SDL_RenderClear(renderer);
                        
                        
                //         if (event.type == SDL_KEYDOWN)
                //         {
                //             if (event.key.keysym.sym == SDLK_ESCAPE) {
                //                 done = SDL_TRUE;
                //                 break ;
                //             }
                //         }
                //     }
                // }
                // while (SDL_PollEvent(&event)) {
                //     if (event.type == SDL_QUIT) {
                //         break;
                //     }
                // }
*/
