NAME = nibbler
LIB1 = libncurses.so
LIB2 = libsfml.so
LIB3 = libsdl.so
HEADER = includes/
FLAGS =  -fPIC -Wall -Wextra -Werror -g -std=c++11 -Ofast
DIRSRCS = srcs/
DIROBJ = objs/
DIRLIB = lib/
INCLUDES = includes/
PWD = $(shell pwd)
CC = clang++
SRCDIR = srcs/


SRCFILES = $(addprefix $(DIRSRCS), \
	main.cpp \
	Library.class.cpp \
	Game.class.cpp \
	Snake.class.cpp \
	SnakeFood.class.cpp \
	SnakeHelper.class.cpp \
	SnakeMove.class.cpp \
	Exception.class.cpp)

DIRLIB1 = lib1/
LIB1SRC = $(addprefix $(DIRLIB1), \
	Ncurses.class.cpp)

DIRSFML = SFML
SFML_ARCHIVE = SFML-2.2-osx-clang-universal
DIRLIB2 = lib2/
LIB2SRC = $(addprefix $(DIRLIB2), \
	sfml.class.cpp)
SFMLFRAMEWORK = -F$(PWD)/SFML/Frameworks -framework SFML
SFMLLIBS = -L$(PWD)/SFML/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
SFML_INCLUDES = $(PWD)/SFML/include

DIRLIB3 = lib3/
LIB3SRC = $(addprefix $(DIRLIB3), \
	SDL.class.cpp)

all: init $(NAME) \
	$(DIRLIB)$(LIB1) \
	$(DIRLIB)$(LIB2) \
	$(DIRLIB)$(LIB3)

init: $(DIRSFML) $(DIRLIB)

$(DIRSFML):
	@echo "\033[32mDownloading SFML Please wait...\033[0m"
	@curl -L -O -# --progress-bar  http://www.sfml-dev.org/files/$(SFML_ARCHIVE).tar.gz
	@tar -xf $(SFML_ARCHIVE).tar.gz
	@mv $(SFML_ARCHIVE) $(DIRSFML)
	@cd $(DIRSFML)/Frameworks/ && ln -s ../extlibs/freetype.framework
	@cd $(DIRSFML)/Frameworks/ && ln -s ../extlibs/sndfile.framework
	@rm $(SFML_ARCHIVE).tar.gz
	@cd lib2 && ln -s ../SFML/include/SFML SFML
	@echo "\033[33m$(DIRSFML) Downloaded successfully\033[0m \n"

$(DIRLIB):
	@mkdir -p $(DIRLIB)

$(NAME):
	@echo "\033[32mCompiling $(@)\033[0m"
	@$(CC) $(FLAGS) -o $(@) $(SRCFILES) -ldl
	@echo "\033[33m\033[33m$(@) was compiled successfully\033[0m \n"

$(DIRLIB)$(LIB1):
	@echo "\033[32mCompiling $(@)\033[0m"
	@$(CC) $(FLAGS) -o $@ $(LIB1SRC) -shared -I . -lncurses
	@echo "\033[33m\033[33m$(@) was compiled successfully\033[0m \n"

$(DIRLIB)$(LIB2):
	@echo "\033[32mCompiling $(@)\033[0m"
	@$(CC) $(FLAGS) -o $@ $(LIB2SRC) -shared -I . -I $(SFML_INCLUDES) $(SFMLFRAMEWORK) $(SFMLLIBS) -dynamiclib -rpath $(PWD)/$(DIRSFML)/lib -rpath $(PWD)/$(DIRSFML)/Frameworks
	@echo "\033[33m\033[33m$(@) was compiled successfully\033[0m \n"

$(DIRLIB)$(LIB3):
	@echo "\033[32mCompiling $(@)\033[0m"
	@$(CC) $(FLAGS) -o $@ $(LIB3SRC) -shared -I . -lSDL2 -I ~/.brew/include -L ~/.brew/lib
	@echo "\033[33m\033[33m$(@) was compiled successfully\033[0m"

clean:
	@rm -f `find . -name "*~"`
	@echo "\033[33m\033[33mAll neccessary files removed successfully\033[0m"

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(DIRLIB)
	@rm -rf $(DIRSFML)
	@rm -rf nibbler.dSYM

re: fclean all
