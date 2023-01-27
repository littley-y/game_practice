#ifndef __MAP_HPP__
#define __MAP_HPP__

#include "so_long.hpp"

class Map {
 private:
  typedef enum { EXIT, TICKET, START, ENEMY } Type;
  typedef ft::vector<std::string> strVec;

  strVec map;
  size_t size;
  int cnt[4];

 public:
  void setMap(std::ifstream& ifs);
  void checkMap();
  bool checkWall(const std::string& line, int idx) const;
  bool setElem(const std::string& line);
  int getTicketCnt() const;
  void decreaseTicketCnt();
  strVec getMap() const;

  std::string& operator[](int idx);
};

#endif  // __MAP_HPP__