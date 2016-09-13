/**
 * @file tetris_game_piece.h
 * @author Cameron Milsom
 * @brief Represents the User controlled game piece.
 *
 * Represents the user controlled game piece.
 * Interface for manipulate the user game piece.
 */
#ifndef INCLUDE_GAME_TETRIS_GAME_PIECE_H_
#define INCLUDE_GAME_TETRIS_GAME_PIECE_H_


#include <3ds.h>
#include <stdbool.h>
#include "../include/game/game_board/tetris_board.h"
#include "../include/game/block/piece/tetris_piece.h"


/**
 * @brief The User Controlled Game Piece.
 *
 * Represents the user controlled game piece.
 */
typedef struct _TetrisGamePiece TetrisGamePiece;

/**
 * @brief Moves the current piece on the board by the parameters.
 *
 * Moves the current piece by the parameters.
 * Returns a bool if Succeeded or Failed
 *
 * @param self The TetrisBoard struct to reference.
 * @param blocks_down The amount of blocks on the board to move the piece down.
 * @param blocks_right The amount of blocks on the board to move the piece right.
 * @return A bool representing if the piece was successfully moved.
 */
extern bool tetris_game_piece_move_current_piece(TetrisBoard *self, u16 blocks_down, u16 blocks_right);

/**
 * @brief Rotates the current user piece on the board.
 *
 * @param self The TetrisBoard struct to reference.
 * @param rotations the amount of piece rotations.
 * @return True if the rotation occurred.
 */
extern bool tetris_game_piece_rotate_current_piece(TetrisBoard *self, u8 rotations);

/**
 * @brief Gets the current piece on the board.
 *
 * Returns a TetrisPiece that represents the current piece on the board.
 * This piece is in control by the user.
 *
 * @param self The TetrisGamePiece struct to reference
 * @return The current TetrisPiece on the board.
 */
extern TetrisPiece *tetris_game_piece_get_current_piece(TetrisGamePiece *self);



#endif
