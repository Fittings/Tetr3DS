/**
 * @file pieces.h
 * @author Cameron Milsom
 * @brief Generates TetrisPieces
 *
 * Represents a Set of TetrisPieces
 */
#ifndef INCLUDE_PIECES_H_
#define INCLUDE_PIECES_H_

#include "../include/game/block/piece/tetris_piece.h"


//Standard Pieces

/**
 * @brief Creates the standard 0 Block
 *
 * @return A TetrisPiece with the 0 Block shape;
 */
extern TetrisPiece *create_O();

/**
 * @brief Creates the standard I Block
 *
 * @return A TetrisPiece with the I Block shape;
 */
extern TetrisPiece *create_I();

/**
 * @brief Creates the standard Z Block
 *
 * @return A TetrisPiece with the Z Block shape;
 */
extern TetrisPiece *create_Z();

/**
 * @brief Creates the standard S Block
 *
 * @return A TetrisPiece with the S Block shape;
 */
extern TetrisPiece *create_S();

/**
 * @brief Creates the standard L Block
 *
 * @return A TetrisPiece with the L Block shape;
 */
extern TetrisPiece *create_L();

/**
 * @brief Creates the standard J Block
 *
 * @return A TetrisPiece with the J Block shape;
 */
extern TetrisPiece *create_J();

/**
 * @brief Creates the standard T Block
 *
 * @return A TetrisPiece with the T Block shape;
 */
extern TetrisPiece *create_T();




#endif
