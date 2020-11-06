#include "../include/linuxParser.h"
#include "../include/process.h"
#include "../include/processParser.h"
#include "../include/renderer.h"
#include <iostream>

using namespace std;

int main() {

  // Declare and initialize the renderer
  Renderer r;

  // Necesary first refresh!!
  refresh();

  // Create windows for the OS stats
  Window_attr os_window{20, r.max_col, r.y, r.x};
  r.create_new_border_win(os_window);
  Window_attr OS_window_keys{18, r.max_col/3, getbegy(os_window.w), getbegx(os_window.w)};
  r.create_sub_win(os_window.w, OS_window_keys);
  Window_attr OS_window_values{18, (r.max_col/3)*2, getbegy(os_window.w), getmaxx(OS_window_keys.w)};
  r.create_sub_win(os_window.w, OS_window_values);

  // Create windows for the processes.
  getmaxyx(os_window.border, r.y, r.x);
  Window_attr processes_window{50, r.max_col, r.y, 0};
  r.create_new_border_win(processes_window);
  Window_attr processes_window_keys{48, r.max_col/3, getbegy(processes_window.w), getbegx(processes_window.w)};
  r.create_sub_win(processes_window.w, processes_window_keys);
  Window_attr processes_window_values{48, (r.max_col/3)*2, getbegy(processes_window.w), getmaxx(processes_window_keys.w)};
  r.create_sub_win(processes_window.w, processes_window_values);

  refresh();

  // The linuxParser will be in one window
  // The ProcessParser will be in another window
  int ch;
  // Quit program on letter q pressed

  LinuxParser lp;

  wprintw(OS_window_keys.w, "OS Release:\n");
  wprintw(OS_window_keys.w, "Uptime:\n");
  wprintw(OS_window_keys.w, "CPU Time:\n");
  wprintw(OS_window_keys.w, "RAM Usage:\n");
  wprintw(OS_window_keys.w, "Total Processes:\n");
  wprintw(OS_window_keys.w, "Running Processes:\n");
  wrefresh(OS_window_keys.w);
  wprintw(OS_window_values.w, lp.os_release().c_str());

  while ((ch = getch()) != 'q') {
    getyx(os_window.w, r.y, r.x);
    std::wstring str{std::to_wstring(ch)};
    waddwstr(processes_window_keys.w, str.c_str());
    waddwstr(processes_window_values.w, str.c_str());
    waddwstr(OS_window_keys.w, str.c_str());
    waddwstr(OS_window_values.w, str.c_str());

    //TODO: Convert integers/floats to strings so we can print them

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
    wrefresh(OS_window_values.w);
    wrefresh(processes_window_keys.w);
    wrefresh(processes_window_values.w);
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
