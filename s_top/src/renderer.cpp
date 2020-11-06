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
  local_win.w = newwin(local_win.max_y, local_win.max_x, local_win.y_coor, local_win.x_coor);
  windows.push_back(local_win);
  box(local_win.w, 0, 0);
  wrefresh(local_win.w);  /* Show that box 		*/
  // Get the x and y coordinates for the current window
  getyx(local_win.w, y, x);
}

void Renderer::print_window(Window_attr& local_win){
  // Make sure we dont overlap the borders
  if(getcury(local_win.w) == 0) local_win.y_coor = 1;
  if(getcurx(local_win.w) == 0) local_win.x_coor = 1;
  if(getcurx(local_win.w) == (local_win.max_x - 1)){
    local_win.y_coor +=1;
    local_win.x_coor = 1;
  }
  mvwprintw(local_win.w, local_win.y_coor, local_win.x_coor, "s");
  wmove(local_win.w, local_win.y_coor, local_win.x_coor + 1);
}

void Renderer::destroy_win(Window_attr& local_win) {
  /* box(local_win, ' ', ' '); : This won't produce the desired
   * result of erasing the window. It will leave it's four corners
   * and so an ugly remnant of window.
   */
  wborder(local_win.w, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
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
  wrefresh(local_win.w);
  delwin(local_win.w);
  //TODO: Overload == operator before we can search and delete
  //windows.remove(local_win);
}
