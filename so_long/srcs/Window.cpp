#include "Window.hpp"

Window::Window(int newWidth, int newHeight)
    : width(newWidth), height(newHeight) {
  mlx = mlx_init();
  win = mlx_new_window(mlx, width, height, ch("so_long"));
}

Window::~Window() {}

void Window::imgToWin(void* img, int x, int y) {
  mlx_put_image_to_window(mlx, win, img, x * 64, y * 64);
}

void Window::putImages(const Map& map, objImg& pic) {
  Map tmp;

  tmp = map;
  for (size_t i = 0; i != tmp.width(); i++) {
    for (size_t j = 0; j != tmp[i].size(); j++) {
      imgToWin(pic.bg.img, j, i);
      if (tmp[i][j] == '1')
        imgToWin(pic.wall.img, j, i);
      else if (tmp[i][j] == 'P')
        imgToWin(pic.pf.img, j, i);
      else if (tmp[i][j] == 'C')
        imgToWin(pic.ticket.img, j, i);
      else if (tmp[i][j] == 'E')
        imgToWin(pic.exit.img, j, i);
      else if (tmp[i][j] == 'X')
        imgToWin(pic.enemy.img, j, i);
    }
  }
}

void Window::setImages(objImg& pic) {
  pic.bg.img = mlx_xpm_file_to_image(mlx, ch("images/bg.xpm"), &width, &height);
  pic.ticket.img =
      mlx_xpm_file_to_image(mlx, ch("images/ticket.xpm"), &width, &height);
  pic.exit.img =
      mlx_xpm_file_to_image(mlx, ch("images/exit_x.xpm"), &width, &height);
  pic.pf.img =
      mlx_xpm_file_to_image(mlx, ch("images/pf0.xpm"), &width, &height);
  pic.wall.img =
      mlx_xpm_file_to_image(mlx, ch("images/wall.xpm"), &width, &height);
  pic.enemy.img =
      mlx_xpm_file_to_image(mlx, ch("images/enemy.xpm"), &width, &height);
  pic.enemy2.img =
      mlx_xpm_file_to_image(mlx, ch("images/enemy2.xpm"), &width, &height);
}

void Window::setPlayerImages(playerImg& pl) {
  pl.pl[0].img =
      mlx_xpm_file_to_image(mlx, ch("images/pl0.xpm"), &width, &height);
  pl.pl[1].img =
      mlx_xpm_file_to_image(mlx, ch("images/pl1.xpm"), &width, &height);
  pl.pl[2].img =
      mlx_xpm_file_to_image(mlx, ch("images/pl2.xpm"), &width, &height);
  pl.pf[0].img =
      mlx_xpm_file_to_image(mlx, ch("images/pf0.xpm"), &width, &height);
  pl.pf[1].img =
      mlx_xpm_file_to_image(mlx, ch("images/pf1.xpm"), &width, &height);
  pl.pf[2].img =
      mlx_xpm_file_to_image(mlx, ch("images/pf2.xpm"), &width, &height);
  pl.pb[0].img =
      mlx_xpm_file_to_image(mlx, ch("images/pb0.xpm"), &width, &height);
  pl.pb[1].img =
      mlx_xpm_file_to_image(mlx, ch("images/pb1.xpm"), &width, &height);
  pl.pb[2].img =
      mlx_xpm_file_to_image(mlx, ch("images/pb2.xpm"), &width, &height);
  pl.pr[0].img =
      mlx_xpm_file_to_image(mlx, ch("images/pr0.xpm"), &width, &height);
  pl.pr[1].img =
      mlx_xpm_file_to_image(mlx, ch("images/pr1.xpm"), &width, &height);
  pl.pr[2].img =
      mlx_xpm_file_to_image(mlx, ch("images/pr2.xpm"), &width, &height);
}

int Window::exitHook() {
  std::cout << "Bye!\n";
  mlx_destroy_window(mlx, win);
  exit(0);
  return (0);
}

int Window::putString(int count) {
  std::string num = std::to_string(count);

  mlx_string_put(mlx, win, (width / 2) - 16, height / 2 - 10, 0xFF000000,
                 ch("MOVE"));
  mlx_string_put(mlx, win, (width / 2) - (num.size() + 5), height / 2,
                 0xFF000000, ch(num.c_str()));
  return (0);
}

int Window::putMsgExit(std::string str) {
  std::cout << str << std::endl;
  mlx_destroy_window(mlx, win);
  exit(0);
  return (0);
}