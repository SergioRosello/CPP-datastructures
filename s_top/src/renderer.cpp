#include "../include/renderer.h"

// Coordinates are passed in (y, x) order to draw

Renderer::Renderer() {
  x = 0;
  y = 0;
  initscr();
  raw();
  noecho();
  keypad(stdscr, TRUE);
  getmaxyx(stdscr, max_row, max_col);
}

void Renderer::create_new_win(Window_attr& local_win) {
  local_win.border = newwin(local_win.max_y, local_win.max_x, local_win.y_coor, local_win.x_coor);
  box(local_win.border, 0, 0);
  wrefresh(local_win.border);  /* Show that box 		*/
  // Get the x and y coordinates for the current window
  local_win.w = derwin(local_win.border, local_win.max_y - 2, local_win.max_x - 2, 1, 1);
  wrefresh(local_win.w);  /* Show that box 		*/
  getyx(local_win.w, y, x);
  windows.push_back(local_win);
}

void Renderer::print_window(Window_attr& local_win){
  wprintw(local_win.w, "Buenas, amigos, que tal las bestias?");
}

void Renderer::destroy_win(Window_attr& local_win) {
  /* box(local_win, ' ', ' '); : This won't produce the desired
   * result of erasing the window. It will leave it's four corners
   * and so an ugly remnant of window.
   */
  wborder(local_win.border, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
  /* The parameters taken are
   * 1. win: the window on which to operate
   * 2. ls: character to be used for the left side of the window
   * 3. rs: character to be used for the right side of the window
   * 4. ts: character to be used for the top side of the window
   * 5. bs: character to be used for the bottom side of the window
   * 6. tl: character to be used for the top left corner of the window
   * 7. tr: character to be used for the top right corner of the window
   * 8. bl: character to be used for the bottom left corner of the window
   * 9. br: character to be used for the bottom right corner of the window
   */
  wrefresh(local_win.border);
  wrefresh(local_win.w);
  delwin(local_win.border);
  delwin(local_win.w);
  //TODO: Overload == operator before we can search and delete
  //windows.remove(local_win);
}
