#include <ncurses.h>
#include <assert.h>
#include <list>

struct Window_attr {
  int max_y, max_x ;
  int y_coor, x_coor;
  WINDOW* border = nullptr;
  WINDOW* w = nullptr;
};

class Renderer {
private:
  // Vector of windows
  std::list<Window_attr> windows;
public:
  // Max screen coordinates
  int max_row, max_col;
  // Coordinates of the current cursor
  int x = 0, y = 0;
  Renderer();
  void init();
  void create_new_border_win(Window_attr&);
  void create_sub_win(WINDOW*, Window_attr&);
  void create_new_win(Window_attr&);
  void destroy_win(Window_attr&);
};

// Windows vector
// To initialize, 
// Window_attr os_window{characteristics}:
// create_new_win returns the window attributes to the initial object by reference
// int create_new_win(Window_attr os_window)
