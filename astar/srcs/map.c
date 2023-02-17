#include "astar.h"

static int iselem(int c) {
  if (c == 'E' || c == '0' || c == '1' || c == 'P')
    return (1);
  else
    return (0);
}

static int check_elem(char* line, int* start, int* end, size_t width) {
  size_t i;

  i = 0;
  while (++i < width) {
    if (!iselem(line[i]))
      return (ERROR);
    if (line[i] == 'E')
      (*end)++;
    if (line[i] == 'P')
      (*start)++;
  }
  return (0);
}

static int check_line(char* line, int index, int height, size_t width) {
  int i;

  i = -1;
  if (index == 1 || index == height) {
    while (++i < (int)width) {
      if (line[i] != '1')
        return (ERROR);
    }
  } else {
    if (line[++i] != '1' || line[width - 1] != '1')
      return (ERROR);
  }
  return (0);
}

static void check_map(t_list* map) {
  t_list* line;
  size_t width;
  int start;
  int end;

  line = map;
  width = ft_strlen(line->content) - 1;
  start = 0;
  end = 0;
  while (line != NULL) {
    if (ft_strlen(line->content) - 1 != width)
      puterror_exit("Not stable line!");
    if (check_line(line->content, line->index, ft_lstsize(map), width))
      puterror_exit("Wall problem!");
    if (check_elem(line->content, &start, &end, width))
      puterror_exit("Wrong elements!");
    line = line->next;
  }
  if (!start || !end)
    puterror_exit("Not enough elements!");
  else if (start > 1)
    puterror_exit("Too many starting points!");
}

void get_map(t_list** map, int fd) {
  int i;
  t_list* temp;

  i = 0;
  while (++i) {
    temp = ft_lstnew(i);
    temp->content = get_next_line(fd);
    if (!temp->content || !temp->content[0]) {
      ft_lstdelone(temp, &free);
      temp = NULL;
      break;
    }
    ft_lstadd_back(map, temp);
  }
  if (*map == NULL)
    puterror_exit("Empty map!");
  check_map(*map);
}
