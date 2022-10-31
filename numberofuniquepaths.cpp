#include <vector>
// represent each spot as a node
// at each node, you have to do:
/*  

    unordered_map<vector<int>,int>'
    if(map[spot] does not exist):

    if(DOWN is finish), map[spot] = 1; return 1;
    if(RIGHT is finish), map[spot] = 1; return 1;
    

    if(DOWN exists and RIGHT exists, but is not finish)
        paths = getPaths(down) + getPaths(right)
        map[spot] = paths;
        return paths;
    else if(DOWN exists)
        paths = getPaths(down)
        map[spot] = paths;
        return paths;
    else if (RIGHT exists)
        paths = getPaths(right)
        map[spot] = paths;
        return paths;
    else // NOTHING EXISTS {
        return 0;
    }
    
*/

bool checkIfExists(vector<int> coords, vector<vector<int> grid) {

    bool exists = true;
    // check Y dimensions
    if(coords[1] >= grid.length) return false;
    if(coords[0] >= grid[0].length) return false;

    if(grid[coords[0]][coords[1]] == 1) return false;
    return true;
}