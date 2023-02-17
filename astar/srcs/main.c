#include "astar.h"

static int check_file(int ac, char* map_name) {
  char* xts;
  int fd;

  if (ac == 1)
    puterror_exit("No map!");
  if (ac > 2)
    puterror_exit("Too many arguments!");
  fd = open(map_name, O_RDONLY);
  if (fd == -1)
    puterror_exit("Wrong files!");
  xts = ft_strrchr(map_name, '.');
  if (!xts)
    puterror_exit("Wrong extension!");
  if (ft_strncmp(xts, ".ber", ft_strlen(xts)))
    puterror_exit("Wrong extension!");
  return (fd);
}

int main(int ac, char** av) {
  int fd;
  t_list* map;

  fd = check_file(ac, av[1]);
  map = NULL;
  get_map(&map, fd);
  mlx_game(&map);
  return (0);
}
