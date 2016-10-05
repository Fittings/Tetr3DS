/**
 * @file tetris_board_controller.h
 * @author Cameron Milsom
 * @brief Controls the direct state of the board.
 *
 * Controls the direct state of the board.
 * All board changes should be handled by this controller.
 */
#ifndef INCLUDE_GAME_GAME_BOARD_TETRIS_BOARD_CONTROLLER_H_
#define INCLUDE_GAME_GAME_BOARD_TETRIS_BOARD_CONTROLLER_H_

#include "../include/game/game_board/tetris_board.h"
#include "../include/game/game_board/tetris_board_piece.h"
#include "../../include/general/region/region.h"
#include "../include/game/game_board/tetris_board_view.h"

/**
 * @brief The Tetris Board Controller
 *
 * Handles the state of the TetrisBoard and TetrisPiece on the board.
 */
typedef struct _TetrisBoardController TetrisBoardController;

/**
 * @brief Initialises a TetrisBoardController.
 *
 * Initialises the TetrisBoardController.
 *
 * @param board The TetrisBoard used in the TetrisBoardController.
 * @return The TetrisBoardController struct.
 */
extern TetrisBoardController *tetris_board_controller_init(TetrisBoard *board);

/**
 * @brief Frees the TetrisBoardController
 *
 * Frees the TetrisBoardController.
 *
 * @param self The TetrisBoardController struct to reference.
 */
extern void tetris_board_controller_free(TetrisBoardController *self);

/**
 * @brief Removes completed rows from the TetrisBoard
 *
 * Removes any rows on the TetrisBoard that are completed. (Excluding any excluded blocks)
 *
 * @param self The TetrisBoardController struct to reference.
 */
extern void tetris_board_controller_remove_completed_rows(TetrisBoardController *self);

/**
 * @brief Spawns a TetrisPiece onto the board that can be controlled.
 *
 * Spawns a TetrisPiece on the board that can be controller through the interfaces.
 *
 * @param self The TetrisBoardController struct to reference.
 * @param piece The TetrisPiece to spawn on the board.
 */
extern void tetris_board_controller_spawn_piece(TetrisBoardController *self, TetrisPiece *piece);

/**
 * @brief Moves the current TetrisPiece on the board.
 *
 * Moves the current TetrisPiece on the board.
 *
 * @param self The TetrisBoardController struct to reference.
 * @param x_offset The amount of units on the x-axis to the right to move the TetrisPiece by.
 * @param y_offset The amount of units on the y-axis to the bottom to move the TetrisPiece by.
 */
extern void tetris_board_controller_move_current_piece(TetrisBoardController *self, s8 x_offset, s8 y_offset);

/**
 * @brief Rotates the current TetrisPiece on the board.
 *
 * Rotates the current TetrisPiece on the board.
 *
 * @param self The TetrisBoardController struct to reference.
 * @param rotations The amount of rotations to move the TetrisPiece by.
 */
extern void tetris_board_controller_rotate_current_piece(TetrisBoardController *self, s8 rotations);

/**
 * @brief Commits the current TetrisPiece to the board.
 *
 * Adds all the blocks of the TetrisPiece to the board and sets the TetrisPiece to NULL.
 *
 * @param self The TetrisBoardController struct to reference.x
 */
extern void tetris_board_controller_commit_piece(TetrisBoardController *self);

/**
 * @brief Drops the current TetrisPiece to the board.
 *
 * Drops the current TetrisPiece to the board and commits it.
 *
 * @param self The TetrisBoardController struct to reference.
 */
extern void tetris_board_controller_drop_current_piece(TetrisBoardController *self);

/**
 * @brief Returns true if the given TetrisPiece can be spawned.
 *
 * @param self The TetrisBoardController struct to reference.
 * @param piece A TetrisPiece to check if it can be spawned on the board.
 * @return True if the piece is valid at the spawn position.
 */
extern bool tetris_board_controller_can_spawn_piece(TetrisBoardController *self, TetrisPiece *piece);

/**
 * @brief Returns true if there is a TetrisPiece in the TetrisBoardController
 *
 * @param self The TetrisBoardController struct to reference.
 * @return true If there is no current TetrisPiece on the board.
 */
extern bool tetris_board_is_current_piece(TetrisBoardController *self);

/**
 * @brief Returns true if the current TetrisPiece can move.
 *
 * Returns true if the current TetrisPiece can move by the given offsets.
 *
 * @param self The TetrisBoardController struct to reference.
 * @param x_offset The amount of units on the x-axis to the right to move the TetrisPiece by.
 * @param y_offset The amount of units on the y-axis to the bottom to move the TetrisPiece by.
 * @return Returns true if the current TetrisPiece can move by the given offsets.
 */
extern bool tetris_board_can_current_piece_move(TetrisBoardController *self, s8 x_offset, s8 y_offset);

/**
 * @brief Draws the TetrisBoard with the current TetrisPiece and the TetrisPiece shadow.
 *
 * Draws the TetrisBoard, TetrisPiece and TetrisPiece shadow in the currently set region.
 *
 * @param self The TetrisBoardStruct to reference.
 */
extern void tetris_board_controller_draw(TetrisBoardController *self, Region *region, u32 block_size);





#endif
