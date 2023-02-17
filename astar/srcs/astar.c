#include "astar.h"

int heuristic(t_node* curr, int goal_x, int goal_y) {
  return (abs(curr->x - goal_x) + abs(curr->y - goal_y));
}

t_node* create_node(int x, int y) {
  t_node* new = ft_calloc(1, sizeof(t_node));
  new->x = x;
  new->y = y;
  new->f = 2147483647;
  new->g = 2147483647;
  new->h = 2147483647;
  return (new);
}

t_node* get_lowest_f(t_node** list, int count, int* idx) {
  long lowest_f;
  t_node* lowest_node;

  lowest_f = 2147483648;
  lowest_node = NULL;
  for (int i = 0; i < count; i++) {
    if (list[i]->f < lowest_f) {
      lowest_f = list[i]->f;
      lowest_node = list[i];
      *idx = i;
    }
  }
  return (lowest_node);
}

int get_index(t_node** list, int adj_x, int adj_y, int count) {
  for (int i = 0; i < count; i++) {
    if (list[i]->x == adj_x && list[i]->y == adj_y)
      return (i);
  }
  return (-1);
}

void print_path(t_param* main, t_node* curr) {
  int cnt = 0;

  while (curr->parent != NULL) {
    img_to_win(&main->var, main->pic.ticket.img, curr->x, curr->y);
    if (cnt == 0)
      img_to_win(&main->var, main->pic.exit.img, curr->x, curr->y);
    curr = curr->parent;
    cnt++;
  }
  img_to_win(&main->var, main->pic.ticket.img, main->x, main->y);
  img_to_win(&main->var, main->pic.player.img, main->x, main->y);
  printf("fast way : %d\n", cnt);
}

void free_lists(t_node** list, int count) {
  for (int i = 0; i != count; i++)
    free(list[i]);
}

void a_star(t_param* main, int width, int height) {
  t_node* open_list[width * height];
  t_node* close_list[width * height];
  int close_cnt = 0;
  int open_cnt = 1;
  int curr_idx = 0;

  ft_memset(open_list, 0, sizeof(t_node*) * (width * height));
  ft_memset(close_list, 0, sizeof(t_node*) * (width * height));
  open_list[0] = create_node(main->x, main->y);

  while (open_cnt > 0) {
    t_node* curr = get_lowest_f(open_list, open_cnt, &curr_idx);
    if (curr->x == main->ex && curr->y == main->ey) {
      print_path(main, curr);
      free_lists(open_list, open_cnt);
      free_lists(close_list, close_cnt);
      return;
    }
    close_list[close_cnt] = curr;
    close_cnt++;
    while (curr_idx != open_cnt - 1) {
      open_list[curr_idx] = open_list[curr_idx + 1];
      curr_idx++;
    }
    open_cnt--;
    for (int b = -1; b <= 1; b++) {
      for (int a = -1; a <= 1; a++) {
        if ((a == 0 && b == 0) || (abs(a) == 1 && abs(b) == 1))
          continue;
        int adj_x = curr->x + a;
        int adj_y = curr->y + b;
        if (main->map[adj_y][adj_x] == '1')
          continue;
        if (get_index(close_list, adj_x, adj_y, close_cnt) != -1)
          continue;
        int est_g = curr->g + 1;
        int idx = get_index(open_list, adj_x, adj_y, open_cnt);
        if (idx == -1) {
          t_node* adj = create_node(adj_x, adj_y);
          adj->g = est_g;
          adj->h = heuristic(adj, main->ex, main->ey);
          adj->f = adj->g + adj->h;
          adj->parent = curr;
          open_list[open_cnt] = adj;
          open_cnt++;
        } else {
          t_node* adj = open_list[idx];
          if (est_g < adj->g) {
            adj->g = est_g;
            adj->f = adj->g + adj->h;
            adj->parent = curr;
          }
        }
      }
    }
  }
  free_lists(close_list, close_cnt);
  img_to_win(&main->var, main->pic.player.img, main->x, main->y);
  printf("no path!\n");
}