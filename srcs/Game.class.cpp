#include "../includes/Game.class.hpp"

Game::Game(void) :
	_lib(DEFAULT_LIB),
	_snake(NULL),
	score(0),
	g(NULL),
	_state(_PAUSE),
	_size_X(0),
	_size_Y(0),
	_food(NULL)
	//_delay(1000000)
{
	return ;
}

Game::~Game(void) { return ; }

void			Game::initGame(int x, int y)
{
	_size_X = x;
	_size_Y = y;
	_snake = new Snake(x / 2, y / 2, _RIGHT);
	g = LoadLibrary(_lib);
	g->initWindow(x, y);
}

void			Game::startGame(void)
{
	_food = food(_FOOD);
	createGame();
	g->displayWin();
	gameLoop();
}

void Game::gameLoop(void) {
	collision crash;

	while (_state == _PAUSE || _state == _RUNNING) {
		if (_state == _RUNNING) {
			//TODO call move snake function
			_snake->moveSnake(0.01);
			crash = anyCollision();
			if (crash == FOOD) {
				eat(crash, _snake);
				//_delay -= 10000;
			}
			else if (crash != NONE)
				_state = _LOSE;
		}
		if (_state >= _LOSE)
			break ;
		createGame();
		g->displayWin();
		inputManager();
		usleep(10000);
	}
	g->endWindow();
}

void Game::exitKey(input ch) {
	(void)ch;
	_state = _LOSE;
}

void Game::printSnake(void) const {
	t_help::const_iterator i;

	i = _snake->getBody().begin();
	g->snakeParts(std::floor((*i).getX()), std::floor((*i).getY()), _SNAKEHEAD);
	i++;
	while (i != _snake->getBody().end()) {
		g->snakeParts(std::floor((*i).getX()), std::floor((*i).getY()), _SNAKEBODY);
		// std::cout << "food drawn" << std::endl;
	  // std::cout << "Pos X " << std::floor((*i).getX()) << std::endl;
	  // std::cout << "Pos Y " << std::floor((*i).getY()) << std::endl;
		i++;
	}
}

collision Game::anyCollision(void) {
	SnakeHelper const &snakeHead = _snake->getHead();

	if (snakeHead.getX() < 1 || snakeHead.getX() >= _size_X)
		return (WALL);
	else if (snakeHead.getY() < 1 || snakeHead.getY() >= _size_Y)
		return (WALL);
	if (snakeCollision(_snake, *_food))
		return (FOOD);
	if (snakeCollision(_snake, snakeHead))
		return (SNAKE);
	return (NONE);
}

void Game::setDirection(input ch) {
	_snake->setStartDirection(static_cast<direction>(ch));
}

IGraphics *Game::LoadLibrary(lib library) {
	if (g != NULL) {
		g->endWindow();
		delete g;
	}
	return (_library.loadLib(library));
}

void Game::createGame(void) const {
	g->boarder();
	printSnake();
	g->snakeParts(_food->getX(), _food->getY(), _FOOD);
}

SnakeFood *Game::food(type f) {
	int _pos_X = 0;
	int _pos_Y = 0;
	SnakeFood *food_;

	_pos_X = rand() % (_size_X - 1) + 1;
	_pos_Y = rand() % (_size_Y - 1) + 1;
	food_ = new SnakeFood(_pos_X, _pos_Y);
	if (snakeCollision(_snake, *food_) || (_food != NULL && food_->getPosition_X() ==
	 _food->getPosition_X() && food_->getPosition_Y() == _food->getPosition_Y())) {
		delete food_;
		return (food(f));
	}
	return (food_);
}

void Game::eat(collision yum, Snake *mouth) {
	if (yum == FOOD) {
		delete _food;
		_food = food(_FOOD);
		//TODO score
		score += 1;
	}
	g->printScore(score);
	mouth->growSnake(); //TODO
}

bool Game::snakeCollision(Snake *crash, SnakeMove const & az) {
	t_help const &snakeBody = crash->getBody();
	t_help::const_iterator a = snakeBody.begin();
	t_help::const_iterator z = snakeBody.end();

	if (static_cast<SnakeMove const &>(*a) == az)
		a++;
	while (a != z) {
		if (az.getPosition_X() == (*a).getPosition_X() && az.getPosition_Y() == (*a).getPosition_Y())
			return (true);
		a++;
	}
	return (false);
}

input Game::inputManager(void) {
	input ch;
	static key_fct executeInput[] = {
		&Game::setDirection,
		&Game::setDirection,
		&Game::setDirection,
		&Game::setDirection,
		&Game::exitKey,
		&Game::changeLibraries,
		&Game::changeLibraries,
		&Game::changeLibraries,
		&Game::changeGameState,
	};
	ch = g->getInput();
	if (ch == INVALID)
		return (ch);
	(this->*(executeInput[ch]))(ch);
	return (ch);
}

void Game::changeGameState(input ch) {
	(void)ch;
	if (_state == _PAUSE)
		_state = _RUNNING;
	else
		_state = _PAUSE;
}

void Game::changeLibraries(input ch) {
	lib newLibrary = static_cast<lib>(ch - LIB1);

	if (_lib != newLibrary) {
		_lib = newLibrary;
		g = LoadLibrary(newLibrary);
		// if (std::strncmp(reinterpret_cast<const char *>(g), "libsdl.so", 9)) {
		// 	_size_X += 540;
		// 	_size_Y += 380;
		// 	_snake = new Snake(_size_X / 2, _size_Y / 2, _RIGHT);
		// 	g->initWindow(_size_X, _size_Y);
		// } else {
		g->initWindow(_size_X, _size_Y);
		// }
	}
	_state = _PAUSE;
}
