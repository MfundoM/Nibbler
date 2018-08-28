#include  "../includes/Header.hh"
#include  "../includes/Game.class.hpp"
#include  "../includes/Library.class.hpp"
#include  "../includes/Exception.class.hpp"

int main(int argc, char **argv) {
  Game *game;
  int w, h;
  std::srand(std::time(0));

  try {
    if (argc == 3) {
      w = atoi(argv[1]);
      h = atoi(argv[2]);
      if (argv[1][0] != '-' || argv[2][0] != '-') {
        if (w < 50 || h < 20 || w > 50 || h > 20) {
          throw "Bad width or height, Width must be 50 and height 20";
        } else {
          game = new Game();
          game->initGame(w, h);
          game->startGame();
          //delete game;
        }
      } else {
        throw "Negative values not allowed";
      }
    } else {
      throw "Invalid parameters";
    }
  } catch (std::exception &e) {
    std::cout << "Error: ";
    std::cout << e.what() << std::endl;
  } catch (const char *msg) {
    std::cout << "Error: ";
    std::cerr << msg << std::endl;
  }
  return (0);
}
