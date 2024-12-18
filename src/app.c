#include <pthread.h> // Used for multithreading
#include <unistd.h> // Used for the sleep() function
#include <ncurses.h>
#include <signal.h>
#include <stdlib.h>

#include "gui.h"
#include "game_state.h"
#include "game_helpers.h"

static void *game_loop(void* vargp);
static void finish(int sig);
static bool isFinished = FALSE;

pthread_t game_thread;

int main() {

  signal(SIGINT, finish); // Handle interrupt

  // Game setup
  PlayerHand player_hand; 
  GameBoard game_board; 

  initialize_board(&game_board, 20, 10); 


  //TODO: Seperate the the game board with the visuals
  //      The game coordinates are in a 2D array and we draw the 2D array
  //      everytime we update the window

  // Basic curses setup
  initscr();
  curs_set(0);
  keypad(stdscr, TRUE); // Enables the keyboard
  noecho(); // Does not print characters as they are entered
  nonl(); // Return key does not translate as a newline
  cbreak(); // Takes characters without waiting for \n

  // Create game loop thread
  pthread_create(&game_thread, NULL, game_loop, NULL);

  int board_width = 23;
  int board_height = 32;

  WINDOW *game_win = newwin(board_height, board_width, 0, 10);
  refresh();

  w_create_board(game_win, &board_height, &board_width); 
  refresh();
  getch();

  finish(EXIT_SUCCESS);
  return EXIT_SUCCESS;
}

static void* game_loop(void *vargp) {
  for (int i = 1; i <= 5; i++) {
    // Make blocks fall 
    // Cast where the block will land
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
