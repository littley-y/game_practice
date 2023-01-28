#ifndef __MAP_H__
#define __MAP_H__

#include "so_long.hpp"

class Map {
 private:
  typedef enum { EXIT, TICKET, START, ENEMY } Type;
  typedef ft::vector<std::string> strVec;

  strVec map;
  int cnt[4];

 public:
  void readMap(std::ifstream& ifs);
  void checkMap();
  bool checkWall(const std::string& line, size_t idx) const;
  bool setElem(const std::string& line);
  int getTicketCnt() const;
  void decreaseTicketCnt();

  strVec getMap() const;
  size_t width() const;
  size_t height() const;

  std::string& operator[](int idx);
};

#endif  // __MAP_H__