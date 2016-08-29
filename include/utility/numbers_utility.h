/**
 * @file numbers_utility.h
 * @author Cameron Milsom
 * @brief Utility functions relating to numbers
 *
 * Utility class with functions that are useful for numbers.
 */
#ifndef INCLUDE_UTILITY_NUMBERS_UTILITY_H_
#define INCLUDE_UTILITY_NUMBERS_UTILITY_H_

/** Calculates the max of two numbers */
#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

/** Calculates the min of two numbers */
#define min(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })


#endif
