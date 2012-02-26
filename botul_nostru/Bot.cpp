/*
 * =============================================================================
 *
 *       Filename:  Bot.cpp
 *        Authors:  Dodon Victor <dodonvictor at gmail dot com>
 *                  Cernov Vladimir <kaspersky_gg@gmail.com>
 *                  Maldur Vitalie <maldur.vitalik@yahoo.com>
 *                  Straticiuc Vicu <straticiuc_vicu@yahoo.com>
 *        Created:  02/25/2012
 *    Description:  
 *
 * =============================================================================
 */

#include "Bot.h"

void Bot::playGame()
{
    /* Reads in game parameters. */
    LOG("Reading initial parameters.");
    std::cin >> state;
    endTurn();
    
    srand((unsigned int)gparam::seed);

    /* Continues to make moves until game is over. */
    while(std::cin >> state)
    {
        LOG("turn " << state.currentTurnNumber << ":");

        state.mark_visible();
        makeMoves();

        endTurn();
        LOG("Time taken: " << state.timer.getTime() << "ms");
	LOG("Alocated Time: " << gparam::turnTime<<"ms" << std::endl);
    }
}

void Bot::makeMoves()
{
    for (int ant = 0; ant < (int)state.myAnts.size(); ++ant)
    {
        /* Try moving this ant in some random direction. */
        int direction = rand() % 4;
        Location newLocation = state.myAnts[ant].move(direction);
        /* Destination shouldn't be water and shouldn't be an ant. */
        if (!state.grid[newLocation.row][newLocation.col].isWater &&
                state.grid[newLocation.row][newLocation.col].antPlayer == -1)
        {
            /* Move ant. */
            state.grid[newLocation.row][newLocation.col].antPlayer = 0;
            state.grid[state.myAnts[ant].row][state.myAnts[ant].col].antPlayer = -1;
            /* Outputs move information correctly to the engine. */
            std::cout << "o" << " " << state.myAnts[ant].row << " " <<
                    state.myAnts[ant].col << " " << DIRECTION_LETTER[direction] << std::endl; 
        }
    }
}

void Bot::endTurn()
{
    LOG("Sending endTurn()");

    /* If this wasn't the start game, reset the board. */
    if(state.currentTurnNumber > 0)
    {
            state.reset();
    }

    /* Move to next turn. */
    state.currentTurnNumber++;

    std::cout << "go" << std::endl;
}

int Bot::bfs(Location from,Location to)
{
	std::list<Location> squares;
	std::list<Location> changed;

	return 0;
}
