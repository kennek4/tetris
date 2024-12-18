#ifndef H_GAME_HELPERS
#define H_GAME_HELPERS

// Game stats, with the players score, etc.
typedef struct {
  int score;
} Stats;

// Represents a Tetris block
typedef struct {
  int x_pos;
  int y_pos;
} Block;

typedef struct {
  Block* curr;
  Block* held;
} PlayerHand;

#endif // !H_GAME_HELPERS

