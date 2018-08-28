#ifndef LIBRARY_CLASS_HPP
# define LIBRARY_CLASS_HPP

# include "Header.hh"
# include "IGraphics.hpp"
#include "Exception.class.hpp"

class Library {
public:
  Library(void);
  ~Library(void);

  IGraphics *loadLib(lib library);

private:
  static const char *path[3];
};

typedef IGraphics *(*t_create)(void);

#endif
