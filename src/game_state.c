#include "game_state.h"

void initialize_board(GameBoard *g_board, unsigned int board_height, unsigned int board_width) {
  // Initialize a zero in every location
  for (int y = 0; y < board_height; y++) {
    memset(g_board->board[y], 0, board_width * sizeof(unsigned int));
  }  
}
