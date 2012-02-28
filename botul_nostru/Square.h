/*
 * =============================================================================
 *
 *       Filename:  State.h
 *        Authors:  Dodon Victor <dodonvictor at gmail dot com>
 *                  Cernov Vladimir <gg.kaspersky@gmail.com>
 *                  Maldur Vitalie <maldur.vitalik@yahoo.com>
 *                  Straticiuc Vicu <straticiuc_vicu@yahoo.com>
 *        Created:  02/25/2012
 *    Description:  
 *
 * =============================================================================
 */

#include <vector>

// Local includes

#include "global.h"
#include "Logging.h"
#include "Timer.h"

/** Struct for representing a square in the grid. */
class Square
{

public:
    Square();

    /** Resets the information for the square except water information. */
    void reset();
    bool isVisible;

public:
    bool isWater;
    bool isHill;
    bool isFood;
    int isMarked;
    int hillPlayer;
    int antPlayer;
    int myAntNumber;

    std::vector<Square> neighbors;

};