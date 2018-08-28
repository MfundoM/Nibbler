#include "../includes/Library.class.hpp"

const char *Library::path[] = {
  "./lib/libncurses.so",
  "./lib/libsfml.so",//TODO lib2
  "./lib/libsdl.so"//TODO lib3
};

Library::Library(void) { return ; }

Library::~Library(void) { return ; }

IGraphics *Library::loadLib(lib library) {
  t_create  dl_create;
  IGraphics *display;
  void      *dl_handle;

  if ((dl_handle = dlopen(path[library], RTLD_LAZY)) == NULL)
    throw Exception::LibOpen();
  dl_create = reinterpret_cast<t_create>(dlsym(dl_handle, "create"));
  if (dl_create == NULL)
    throw Exception::LibSym();
  display = dl_create();
  if (!display)
    throw Exception::ErrorException();
  return (display);
}
