#include <ncurses.h>

class Renderer {
public:
  int max_row, max_col;
  int x, y;
  Renderer();
  void init();
  WINDOW *create_newwin(int height, int width, int starty, int startx);
  void destroy_win(WINDOW *local_win);
};
