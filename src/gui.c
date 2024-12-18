#include "gui.h"

#define MAX_ASCII_LINE 500

void print_art(WINDOW *win, char *file, int x, int y) {
  FILE *fp = fopen(file, "r");
  if (fp == NULL) {
    exit(EXIT_FAILURE);
  }
  fclose(fp);
}

void w_draw_board(WINDOW *win, unsigned char *board[20][10], unsigned char *board_height, unsigned char *board_width) {
   
}

// TODO: Might remove this with a different implementation
void w_create_board(WINDOW *win, int *board_height, int *board_width) {
  box(win, 0, 0);
  wrefresh(win);
} 
