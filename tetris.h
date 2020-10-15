/*
 * Professional MultiSwimmers
 * ECE 4440
 * 
 * tetris.h
 * 
 * Author: Daniel Mizrahi
 * Ported by: Patrick Thomas
 */

#ifndef TETRIS_H_
#define TETRIS_H_

#include "msp.h"
#include "rand.h"

#define GAME_WIDTH 10
#define GAME_HEIGHT 20
#define PIECE_QUEUE_SIZE 6

#define EMPTY 0
#define OCCUPIED 1

#define true 1
#define false 0

typedef unsigned char bool;

typedef struct {
    unsigned char x, y;
} Point;

typedef struct {
    Point a, b, c, d;
} State;

typedef union {
    State state;
    Point points[4];
} StateUnion;

typedef struct
{
    unsigned char piece_num;
    unsigned char state;
    State *states;
    unsigned char num_states;
} Piece;

typedef struct
{
    unsigned char board[GAME_HEIGHT][GAME_WIDTH];
    unsigned char score;
    unsigned char row;
    unsigned char col;
    unsigned char end_game;
    unsigned char lines_cleared;
    Piece piece_queue[PIECE_QUEUE_SIZE];
    unsigned char piece_queue_front;
    unsigned char piece_queue_back;
} Tetris;

static State PIECE_I_STATES[2] = {
    {{0, 0}, {0, 1}, {0, 2}, {0, 3}},
    {{0, 2}, {1, 2}, {2, 2}, {3, 2}}};
static State PIECE_O_STATE =
    {{0, 1}, {0, 2}, {1, 1}, {1, 2}};
static State PIECE_T_STATES[4] = {
    {{0, 0}, {0, 1}, {0, 2}, {1, 1}},
    {{0, 1}, {1, 0}, {1, 1}, {2, 1}},
    {{1, 1}, {2, 0}, {2, 1}, {2, 2}},
    {{0, 1}, {1, 1}, {2, 1}, {1, 2}}};
static State PIECE_S_STATES[2] = {
    {{0, 1}, {0, 2}, {1, 0}, {1, 1}},
    {{0, 1}, {1, 1}, {1, 2}, {2, 2}}};
static State PIECE_Z_STATES[2] = {
    {{0, 0}, {0, 1}, {1, 1}, {1, 2}},
    {{0, 1}, {1, 1}, {1, 0}, {2, 0}}};
static State PIECE_L_STATES[4] = {
    {{0, 0}, {0, 1}, {0, 2}, {1, 0}},
    {{0, 0}, {0, 1}, {1, 1}, {2, 1}},
    {{0, 2}, {1, 0}, {1, 1}, {1, 2}},
    {{0, 1}, {1, 1}, {2, 1}, {2, 2}}};
static State PIECE_J_STATES[4] = {
    {{0, 0}, {0, 1}, {0, 2}, {1, 2}},
    {{0, 1}, {1, 1}, {2, 1}, {2, 0}},
    {{1, 0}, {2, 0}, {2, 1}, {2, 2}},
    {{0, 1}, {0, 2}, {1, 1}, {2, 1}}};

void piece_init(Piece *piece);
bool piece_rotate(Piece *piece, Tetris *tetris);
bool piece_in_bounds(Piece *piece, Tetris *tetris, int new_state);
void piece_visualize();

void tetris_init(Tetris *tetris, Piece *piece);
bool tetris_shift_down(Tetris *tetris);
bool tetris_move_left(Tetris *tetris);
bool tetris_move_right(Tetris *tetris);
void tetris_place_piece(Tetris *tetris);
void tetris_visualize(Tetris *tetris);
void tetris_spawn_piece(Tetris *tetris);
int tetris_remove_lines_and_score(Tetris *tetris);
void tetris_shift_rows_down(Tetris *tetris, unsigned char row_index);
void tetris_queue_enqueue(Tetris *tetris, Piece *piece);
void tetris_queue_pop(Tetris *tetris);
Piece *tetris_queue_get(Tetris *tetris);

#endif
