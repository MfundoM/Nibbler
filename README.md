# Nibbler

Snake is a classical game from the 70’s. The simplicity of this addictive game resulted on its
availability on most of existing game platforms under a form or another.
For "old" people, Snake means hours and hours of slacking at school, using the mobile phone version
of the Nokia 3310. For youngsters, Snake is a 42/WeThinkCode project referring to an obscure game from
prehistoric ages.

## Objectives

Nibbler is yet another snake video game written in C++ including a major twist: dynamic libraries.
Through this project, we discovered the power and usefullness of dynamic libraries used at runtime.
The goal is split into 4 parts: a main executable and 3 dynamic libraries that the main executable will
load and use at runtime. Each library will embed everything the main executable might need to display
the game and to get the player’s inputs.
The main executable will only focus on the game logic and interact with the dynamic libraries.

## Libraries used in the project
* Ncurses
* SFML and
* SDL

### Ncurses library
![screenshot](/Screenshots/ncurses.png?raw=true)

### SFML library
![screenshot](/Screenshots/sfml.png?raw=true)

### SDL library
![screenshots](/Screenshots/sdl.png?raw=true)

## Running and compiling the project
Run `make` and an executable will compile. This is currently only tested on OS X
Run the program with `./nibbler` along with the map size of ` 50 20` so to run it put in:
`./nibbler 50 20` and the game will launch with the default library `ncurses`.

To switch between the three libraries, use the numbers `1 - 3`. Ncurses is the default library,
SFML follows with 2 and SDL is the third library.
