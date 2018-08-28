#include "../includes/Exception.class.hpp"

const char *Exception::LibOpen::what() const throw() {
  return (dlerror());
}

const char *Exception::LibSym::what() const throw() {
  return (dlerror());
}

const char *Exception::ErrorException::what() const throw() {
  return ("creating display");
}
