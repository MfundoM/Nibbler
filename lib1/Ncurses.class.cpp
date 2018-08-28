#include "Ncurses.class.hpp"

std::map<int, input> Ncurses::_input = Ncurses::createInput();

Ncurses::Ncurses(void) {
  // std::cout << "Ncurses constructor called" << std::endl;
  return ;
  }

Ncurses::~Ncurses(void) {
  // std::cout << "Ncurses destructor called" << std::endl;
  return; }

void Ncurses::initWindow(int w, int h) {
  //initialize private member variables
  _x = w;
  _y = h;
  _snakePart = " ";
  _food = " ";
  _boarder = ' ';

  //initialize window
  initscr();
  noecho();
  curs_set(0);
  keypad(stdscr, TRUE);
  nodelay(stdscr, TRUE);
  _win = newwin(h + 1, w + 1, 0, 0);

  //initialize color
  start_color();
  init_pair(1, COLOR_BLACK, COLOR_RED);
  init_pair(2, COLOR_BLACK, COLOR_GREEN);
	init_pair(3, COLOR_BLACK, COLOR_BLUE);
  init_pair(4, COLOR_BLACK, COLOR_WHITE);
}

void Ncurses::endWindow(void) {
  endwin();
}

void Ncurses::snakeParts(float fx, float fy, type t) {
  int x = static_cast<int>(fx);
  int y = static_cast<int>(fy);

  if (t == _SNAKEHEAD) {
    move(y, x);
		attron(COLOR_PAIR(4));
		addstr(_snakePart);
		attroff(COLOR_PAIR(4));
  } else if (t == _SNAKEBODY) {
    move(y, x);
		attron(COLOR_PAIR(2));
		addstr(_snakePart);
		attroff(COLOR_PAIR(2));
  } else if (t == _FOOD) {
    move(y, x);
		attron(COLOR_PAIR(1));
		addstr(_food);
		attroff(COLOR_PAIR(1));
  }
  return ;
}

input Ncurses::getInput(void) {
  int ch = getch();
  static std::map<int, input>::iterator invalidKey = _input.end();

  if (Ncurses::_input.find(ch) != invalidKey)
    return (Ncurses::_input[ch]);
  else
    return (INVALID);
}

void Ncurses::boarder(void) {
  wclear(_win);

  wattron(_win,COLOR_PAIR(3));
	box(_win, _boarder, _boarder);
	wattron(_win,COLOR_PAIR(3));
  return ;
}

void Ncurses::displayWin(void) {
  wrefresh(_win);
  return ;
}

std::map<int, input> Ncurses::createInput(void) {
  std::map<int, input> ch;

  ch[KEY_UP] = UP;
  ch[KEY_DOWN] = DOWN;
  ch[KEY_LEFT] = LEFT;
  ch[KEY_RIGHT] = RIGHT;
  ch[27] = EXIT;
  ch['1'] = LIB1;
  ch['2'] = LIB2;
  ch['3'] = LIB3;
  ch['p'] = PAUSE;
  return (ch);
}

void Ncurses::printScore(int score) {
  move(_y + 1, 0);
  addstr("Score: ");
  printw("%d", score);
  return ;
}

extern "C" IGraphics * create(void) {
  return (new Ncurses());
}
