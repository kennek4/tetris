#include <pthread.h> // Used for multithreading
#include <unistd.h> // Used for the sleep() function
#include <ncurses.h>
#include <signal.h>
#include <stdlib.h>

static void* game_loop(void* vargp);
static void finish(int sig);
static bool isFinished = FALSE;

pthread_t game_thread;

int main() {

  signal(SIGINT, finish); // Handle interrupt

  // Basic curses setup
  initscr();
  keypad(stdscr, TRUE); // Enables the keyboard
  noecho(); // Does not print characters as they are entered
  nonl(); // Return key does not translate as a newline
  cbreak(); // Takes characters without waiting for \n

  // Create game loop thread
  pthread_create(&game_thread, NULL, game_loop, NULL);

  char input;
  char key[4];

  for (;;) {
    if (!isFinished) {
      addstr("\nPress Any Key ");
      refresh();

      input = getch();
      sprintf(key, " %c\n", input);
      
      addstr(key);
      refresh();
    }
  }

  finish(EXIT_SUCCESS);
  return EXIT_SUCCESS;
}

static void* game_loop(void* vargp) {
  char time[50];
  for (int i = 1; i <= 60; i++) {
    if (isFinished) {
      break; 
    }

    sprintf(time, "\nS:[%d]\n", i);

    sleep(1);
    addstr(time);
    refresh();
  }

  return NULL;
}

/*
*  This function will
*  handle the "clean up" of the program.
*/
static void finish(int sig) {

  pthread_cancel(game_thread);
  isFinished = TRUE;

  endwin();
  exit(EXIT_SUCCESS);
}
