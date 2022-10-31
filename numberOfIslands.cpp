#include <vector>
#include <queue>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        /*
        - mark visited nodes with -1
        - use BFS(i,j,grid), on unvisited nodes
        - after the BFS, increment numberOfIslands by 1
        - for loop through all the spots in the grid until done
        - if it's a '-1' in our for loop, just "continue"
    
        */
        
        int m = grid.size();
        int n = grid[0].size();
        int numOfIslands = 0;
        
        for(int i = 0; i < m; i++) {
            
            for(int j = 0; j < n; j++) {
                
                if(grid[i][j] == '1') {
                    BFS(i,j,grid);
                    numOfIslands++;
                }
            }
        }
        
        return numOfIslands;
    }
    
    void printQueue(queue<pair<int,int>>& q) {
         while (!q.empty())
            {
                cout << " (" << q.front().first << " " << q.front().second << ")";
                q.pop();
            }
            std::cout << std::endl;
    }

    // BFS starting from this [i,j] coordinate
    void BFS(int i, int j, vector<vector<char>>& grid) {
        // # of rows
        int m = grid.size();
        // # of cols
        int n = grid[0].size();
        
        queue<pair<int,int>> myqueue;
        
        pair<int,int> currentPair(i,j);
        myqueue.push(currentPair);
        while(!myqueue.empty()) {
            queue<pair<int,int>> myqueuecopy = myqueue;
            printQueue(myqueuecopy);
            currentPair = myqueue.front();
            myqueue.pop();
            
            grid[currentPair.first][currentPair.second] = '2';
            // [i-1,j] (UP)
            if(currentPair.first > 0) {
                if(grid[currentPair.first-1][currentPair.second] == '1') {
                    pair<int,int> newPair(currentPair.first-1,currentPair.second);
                    myqueue.push(newPair);
                }
            }
            
            // [i+1,j] (DOWN)
            if(currentPair.first < m-1) {
                 if(grid[currentPair.first+1][currentPair.second] == '1') {
                    pair<int,int> newPair(currentPair.first+1,currentPair.second);
                    myqueue.push(newPair);
                }
            }
            
            // [i,j-1] (LEFT)
            if(currentPair.second > 0) {
                 if(grid[currentPair.first][currentPair.second-1] == '1') {
                    pair<int,int> newPair(currentPair.first,currentPair.second-1);
                    myqueue.push(newPair);
                }
            }
            // [i,j+1] (RIGHT)
            if(currentPair.second < n-1) {
                if(grid[currentPair.first][currentPair.second+1] == '1') {
                    pair<int,int> newPair(currentPair.first,currentPair.second+1);
                    myqueue.push(newPair);
                }
            }
            
        }
        
    }
};

int main() {
    Solution x;
    vector<vector<char>> inp ={{'1','1','1','1','1','0','1','1','1','1','1','1','1','1','1','0','1','0','1','1'},{'0','1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','0'},{'1','0','1','1','1','0','0','1','1','0','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','0','0','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','0','1','1','1','1','1','1','0','1','1','1','0','1','1','1','0','1','1','1'},{'0','1','1','1','1','1','1','1','1','1','1','1','0','1','1','0','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','0','1','1'},{'1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'0','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','0','1','1','1','1','1','1','1','0','1','1','1','1','1','1'},{'1','0','1','1','1','1','1','0','1','1','1','0','1','1','1','1','0','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','0'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','0','0'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'}};
    x.numIslands(inp);

    return 0;
}