#include "gui.h"

#define MAX_ASCII_LINE 500
#define VLINE_CHAR '|'
#define HLINE_CHAR '-'

void print_art(WINDOW *win, char *file, int x, int y) {
  FILE *fp = fopen(file, "r");
  if (fp == NULL) {
    exit(EXIT_FAILURE);
  }

  fclose(fp);
}

void create_board(WINDOW *win, int *board_height, int *board_width) {

  box(win, 0, 0);

  for (int y = 1; y < *board_height - 1; y++) {
    for (int x = 1; x < *board_width - 1; x++) {

    }
  }

  wrefresh(win);
} 
