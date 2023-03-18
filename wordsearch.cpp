#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool isValid(int n, int m, int i, int j, vector<vector<char>> board) {
    if( i >= 0 && i < n && j >= 0 && j < m) {
        if(board[i][j] != '_') {
            return true;
        }
    }
    return false;
}

void recursiveExist(vector<vector<char>> board, string word, unordered_map<char,int> map, bool &found,int i, int j) {

    if(found) return;
    if(map.find(board[i][j]) != map.end()) {
        if(map[board[i][j]] == 1) {
            map.erase(board[i][j]);
        }
        else {
            map[board[i][j]]-=1;
        }
    }
    board[i][j] = '_';

    if(map.empty()) {
        found = true;
        return;
    }

    vector<vector<int>> pairs{
        vector<int>{i-1, j},
        vector<int>{i+1, j},
        vector<int>{i, j-1},
        vector<int>{i, j+1}
    };

    for(int a = 0; a < pairs.size(); a++) {
        if(isValid(board.size(),board[0].size(),pairs[a][0],pairs[a][1],board)) {
            recursiveExist(board,word,map,found,pairs[a][0],pairs[a][1]);
        }
    }

}
bool exist(vector<vector<char>>& board, string word) {

    bool fnd = false;
    unordered_map<char,int> mymap;
    for(int i = 0; i < word.length(); i++) {
        if(mymap.find(word[i]) != mymap.end()) {
            mymap[word[i]]+=1;
        }
        else {
            mymap[word[i]] = 1;
        }
    }
    recursiveExist(board,word,mymap,fnd,0,0);

    return fnd;
}


int main() {

    // Test Case 1
    vector<vector<char>> board = {
            {'A','B','C','E'},
            {'S','F','C','S'},
            {'A','D','E','E'}
    };

    string word = "ABCCED";
    cout << exist(board, word) << endl; // expected output: 1

    // Test Case 2
    board = {
            {'A','B','C','E'},
            {'S','F','C','S'},
            {'A','D','E','E'}
    };
    word = "SEE";
    cout << exist(board, word) << endl; // expected output: 1

    // Test Case 3
    board = {
            {'A','B','C','E'},
            {'S','F','C','S'},
            {'A','D','E','E'}
    };
    word = "ABCB";
    cout << exist(board, word) << endl; // expected output: 0

    // Test Case 4
    board = {{'a','a'}};
    word = "aaa";
    cout << exist(board, word) << endl; // expected output: 0

    // Test Case 5
    board = {{'a'}};
    word = "a";
    cout << exist(board, word) << endl; // expected output: 1

    board = {
            {'a','b','c','d','e'},
            {'f','g','h','i','j'},
            {'k','l','m','n','o'},
            {'p','q','r','s','t'},
            {'u','v','w','x','y'},
            {'z','a','b','c','d'}
    };
    word = "abcde";
    cout << exist(board, word) << endl; // expected output: 1

    // Test Case 7
    board = {
            {'a','b','c','d','e'},
            {'f','g','h','i','j'},
            {'k','l','m','n','o'},
            {'p','q','r','s','t'},
            {'u','v','w','x','y'},
            {'z','a','b','c','d'}
    };
    word = "zabcd";
    cout << exist(board, word) << endl; // expected output: 1
}
