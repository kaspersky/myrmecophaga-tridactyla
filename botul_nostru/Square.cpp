/*
 * =============================================================================
 *
 *       Filename:  Square.cpp
 *        Authors:  Dodon Victor <dodonvictor at gmail dot com>
 *                  Cernov Vladimir <gg.kaspersky@gmail.com>
 *                  Maldur Vitalie <maldur.vitalik@yahoo.com>
 *                  Straticiuc Vicu <straticiuc_vicu@yahoo.com>
 *        Created:  02/25/2012
 *    Description:
 *
 * =============================================================================
 */

#include "Square.h"

/** Struct for representing a square in the grid. */
Square::Square(int a, int b)
{
	isVisible = isWater = isHill = isFood = seen = false;
    hillPlayer = antPlayer = myAntNumber = isMarked = foodIndex = -1;
	f = g = h = dir = -1;
    exploreIndex = 500;
	x = a;
	y = b;
}

/** Resets the information for the square except water information. */
void Square::reset()
{
    isVisible = isHill = isFood = false;
    hillPlayer = antPlayer = myAntNumber = -1;
    exploreIndex++;
}
