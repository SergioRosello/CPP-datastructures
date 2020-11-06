#include "../include/linuxParser.h"
#include "../include/process.h"
#include "../include/processParser.h"
#include "../include/renderer.h"
#include <iostream>

using namespace std;

int main() {

  // Declare and initialize the renderer
  Renderer r;

  printw("Press F1 to exit");
  refresh();
  Window_attr os_window{20, r.max_col, r.y, r.x, nullptr};
  r.create_new_win(os_window);

  getmaxyx(os_window.w, r.y, r.x);
  Window_attr processes_window{50, r.max_col, r.y, 0, nullptr};
  r.create_new_win(processes_window);

  // The linuxParser will be in one window
  // The ProcessParser will be in another window
  int ch;
  // Quit program on letter q pressed
  while ((ch = getch()) != 'q') {
    getyx(os_window.w, r.y, r.x);
    r.print_window(os_window);
    std::wstring str{std::to_wstring(r.max_col)};
    waddwstr(processes_window.w, str.c_str());


    // LinuxParser lp;
    // addstr("OS Release: ");
    // cout << "OS release: " << lp.os_release() << endl;
    // cout << "Uptime: " << lp.uptime() << endl;
    // cout << "CPU usage: " << lp.cpu_usage() << endl;
    // cout << "RAM usage: " << lp.ram() << endl;
    // cout << "Total Processes: " << lp.total_processes() << endl;
    // cout << "Running processes: " << lp.running_processes() << endl;
    //// Process parser that gets all current rulling processes and creates
    //// the processes
    // ProcessParser pp;
    // while (true) {
    // pp.get_processes();
    //
    // std::vector<Process> processes;
    // for (auto process : pp.PIDs) {
    //// Create a process object
    ////TODO: Before creating, check wheather the process already exists, with
    ///it's specific pid /then, if it doesn't exist, create the new one. /If the
    ///process exists, update it's fields.
    // Process p(process);
    // processes.push_back(p);
    //}
    //
    // for (auto process : processes) {
    // std::cout << "Process ID: " << process.get_pid()
    //<< " User: " << process.get_user()
    //<< " Command: " << process.get_command()
    //<< " Mem usage: " << process.get_memory_usage() << std::endl;
    //}
    // Refresh the screen, to add everything new
    wrefresh(os_window.w);
    wrefresh(processes_window.w);
    //}
    // TODO: Should be called when the interrupt Ctrl+c is sent to the program.
    // otherwise, i fear it won't work
    // Finish the program
  }
  r.destroy_win(os_window);
  r.destroy_win(processes_window);
  endwin();
  return 0;
}
