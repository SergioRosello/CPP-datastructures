#include "../include/linuxParser.h"
#include "../include/process.h"
#include "../include/processParser.h"
#include "../include/renderer.h"
#include <iostream>

using namespace std;

int main() {

  // Declare and initialize the renderer
  Renderer r;
  // Create two windows
  // cout lines to the pannels through my renderer,
  // so I don't have to operate with coordinates here

  printw("Press F1 to exit");
  refresh();
  WINDOW *os_window{r.create_newwin(20, 239, 0, 0)};
  WINDOW *processes_window{r.create_newwin(50, 239, 20, 0)};
  mvwprintw(os_window, 2, 2, "Hola, esto deberia poder verlo");
  refresh();
  // The linuxParser will be in one window
  // The ProcessParser will be in another window
  int ch;
  while ((ch = getch()) != KEY_F(1)) {
    mvwprintw(os_window, 2, 2, "Hola, esto deberia poder verlo");
    wprintw(processes_window, "Buenas, amigos, aqui estamos");

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
    refresh();
    //}
    // TODO: Should be called when the interrupt Ctrl+c is sent to the program.
    // otherwise, i fear it won't work
    // Finish the program
  }
  //r.destroy_win(os_window);
  //r.destroy_win(processes_window);
  endwin();
  return 0;
}
