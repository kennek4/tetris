#include <ncurses.h>
#include <signal.h>
#include <stdlib.h>

static void finish(int sig);

int main() {

  signal(SIGINT, finish); // Handle interrupt

  // Basic curses setup
  initscr();
  keypad(stdscr, TRUE); // Enables the keyboard
  noecho(); // Does not print characters as they are entered
  nonl(); // Return key does not translate as a newline
  cbreak(); // Takes characters without waiting for \n

  addstr("Press any key");

  char textbuffer[15];
  char c = getch();

  clear();

  sprintf(textbuffer, "You pressed %c\n", c);
  addstr(textbuffer);
  refresh();

  getch();

  finish(EXIT_SUCCESS);
  return 0;
}

/*
*  This function will
*  handle the "clean up" of the program.
*/
static void finish(int sig) {
  endwin();
  exit(EXIT_SUCCESS);
}
