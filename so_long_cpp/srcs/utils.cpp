#include "so_long.hpp"

void putErrExit(std::string str) {
  std::cerr << "Error\n" << str << std::endl;
  exit(1);
}

void getLocation(int* x, int* y, int lx, int ly) {
  *x = lx;
  *y = ly;
}

bool isElem(char c) {
  if (c == 'E' || c == '0' || c == '1' || c == 'C' || c == 'P' || c == 'X')
    return (1);
  else
    return (0);
}

char* ch(const char* str) {
  return (const_cast<char*>(str));
}