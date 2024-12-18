#ifndef H_GAME_STATE
#define H_GAME_STATE

#include <string.h>

typedef struct {
  unsigned char board[20][10];
} GameBoard;

void initialize_board(GameBoard *g_board, unsigned int board_height, unsigned int board_width);

#endif // !H_GAME_STATE
