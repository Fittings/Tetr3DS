/**
 * @file tetris_block.h
 * @author Cameron Milsom
 * @brief A singular point
 *
 * Represents a singular tetris block.
 * Multiple blocks make a singular tetris piece.
 */
#ifndef INCLUDE_GAME_POINT_H_
#define INCLUDE_GAME_POINT_H_

#include "../include/types/colours.h"


/**
 * @brief A 2d point.
 *
 * Represents an X and Y co-ordinate system.
 */
typedef struct _Point Point;



/**
 * @brief Initializes a 2d point
 *
 * Creates a TetrisBlock struct. Tetris blocks are used for creating tetris pieces.
 *
 * @param x The x co-ordinate.
 * @param y The y co-ordinate.
 */
extern Point *point_init(u16 x, u16 y);

/**
 * @brief Frees the Point struct
 *
 * Frees the Point struct.
 * @param self The Point struct to reference.
 */
extern void point_free(Point *self);

/**
 * @brief Returns the x co-ordinate.
 *
 * Returns the x co-ordinate of a 2d plane.
 *
 * @param self The Point struct to reference.
 */
extern u16 point_get_x(Point *self);

/**
 * @brief Returns the y co-ordinate.
 *
 * Returns the y co-ordinate of a 2d plane.
 *
 * @param self The Point struct to reference.
 */
extern u16 point_get_y(Point *self);


#endif
