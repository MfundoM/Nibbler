#ifndef EXCEPTION_CLASS_HPP
# define EXCEPTION_CLASS_HPP

# include "Header.hh"

class Exception {
public:
  class LibOpen : public std::exception {
  public:
    const char *what() const throw();
  };

  class LibSym : public std::exception {
  public:
    const char *what() const throw();
  };

  class ErrorException : std::exception {
  public:
    const char *what() const throw();
  };
};

#endif
