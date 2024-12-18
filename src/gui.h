#ifndef H_GUI
#define H_GUI

#include <ncurses.h>
#include <curses.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Prints ASCII art on the given window with an x, y offset
void print_art(WINDOW *win, char *filename, int x, int y);


void w_draw_board(WINDOW *win, unsigned char *board[20][10] ,unsigned char *board_height, unsigned char *board_width);
void w_create_board(WINDOW *win, int *board_height, int *board_width); 



#endif // !H_GUI
