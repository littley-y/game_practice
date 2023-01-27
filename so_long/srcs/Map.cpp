#include "Map.hpp"

void Map::setMap(std::ifstream& ifs) {
  std::string line;

  while (std::getline(ifs, line))
    map.push_back(line);
  if (map.empty())
    putErrExit("Empty map!");
  size = map[0].size();
  checkMap();
}

void Map::checkMap() {
  strVec tmp;

  tmp = map;
  for (size_t i = 0; i != tmp.size(); i++) {
    if (tmp[i].size() - 1 != size)
      putErrExit("Not stable line!");
    if (checkWall(tmp[i], i))
      putErrExit("Wall problem!");
  }
  if (!cnt[EXIT] || !cnt[TICKET] || !cnt[START] || !cnt[ENEMY])
    putErrExit("Not enough elements!");
  else if (cnt[START] > 1)
    putErrExit("Too many starting points!");
  else if (cnt[ENEMY])
    putErrExit("Too many enemy!");
}

bool Map::checkWall(const std::string& line, int idx) const {
  if (idx == 0 || idx == size - 1) {
    for (size_t i = 0; i != line.size(); i++) {
      if (line[i] != '1')
        return (true);
    }
  } else {
    if (line[0] != '1' || line.back() != '1')
      return (true);
  }
  return (false);
}

bool Map::setElem(const std::string& line) {
  for (size_t i = 0; i != size; i++) {
    if (!isElem(line[i]))
      return (true);
    if (line[i] == 'E')
      ++cnt[EXIT];
    else if (line[i] == 'C')
      ++cnt[TICKET];
    else if (line[i] == 'P')
      ++cnt[START];
    else if (line[i] == 'X')
      ++cnt[ENEMY];
  }
}

std::string& Map::operator[](int idx) {
  return (map[idx]);
}

int Map::getTicketCnt() const {
  return (cnt[TICKET]);
}

void Map::decreaseTicketCnt() {
  --cnt[TICKET];
}

ft::vector<std::string> Map::getMap() const {
  return (map);
}