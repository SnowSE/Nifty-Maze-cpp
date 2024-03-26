#include "Labyrinth.h"
#include <vector>

bool bagContainItem(std::vector<Item> bag, Item found) {
    
    if (found == Item::NOTHING)
        return true;
   
    for (int j = 0; j < bag.size(); j++) {
        if (bag[j] == found)
            return true;
    }
        
    return false;
}

bool isPathToFreedom(MazeCell* start, const std::string& moves) {
    (void) start;
    (void) moves;

    MazeCell* curr = start;

    std::vector<Item> bagOfHolding;

    for (int i = 0; moves[i] != '\0'; i++) {
        char s = moves[i];

        switch (s)
        {
        case 'N':
            curr = curr->north;
            break;
        case 'E':
            curr = curr->east;
            break;
        case 'W':
            curr = curr->west;
            break;
        case 'S':
            curr = curr->south;
            break;
        default:
            break;
        }
        
        if (curr == NULL)
            return false;

        if (!bagContainItem(bagOfHolding, curr->whatsHere)) {
            bagOfHolding.push_back(curr->whatsHere);
        }

    }

    if (bagOfHolding.size() == 3) {
        return true;
    }

    return false;
}


