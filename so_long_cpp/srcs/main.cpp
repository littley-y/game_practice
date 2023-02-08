#include "so_long.hpp"

void check_file(int ac, const std::string& mapName, std::ifstream& ifs) {
  if (ac == 1)
    putErrExit("No map!");
  if (ac > 2)
    putErrExit("Too many arguments!");
  ifs.open(mapName);
  if (ifs.fail())
    putErrExit("Wrong files!");
  if (mapName.find(".ber") != mapName.size() - 4)
    putErrExit("Wrong extension!");
}

int mlx_game(Map& map) {
  Window window(map.width() * 64, map.height() * 64);
  objImg obj;
  playerImg pl;
  Param param(window, map, obj, pl);

  window.setImages(obj);
  window.setPlayerImages(pl);
  window.putImages(map, obj);
  param.getStart();
  mlx_hook(window.win, PRESS, 0, &Param::keyPress, &param);
  mlx_hook(window.win, RED_BUTTON, 0, &Window::exitHook, &param);
  mlx_loop(window.mlx);
  return (0);
}

int main(int ac, char** av) {
  Map map;
  std::ifstream ifs;

  check_file(ac, std::string(av[1]), ifs);
  map.readMap(ifs);
  mlx_game(map);
  return (0);
}
