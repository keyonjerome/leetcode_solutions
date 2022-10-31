#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <set>
#include <algorithm>
using namespace std;

void printvec(vector<string> v, char digit) {
    std::cout << "PRINTVEC " << digit <<  std::endl;
    for(auto i: v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void printvec(vector<int> v) {
    for(auto i: v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}


class Node {

public:
    int val;
    vector<int> path;
    vector<Node> children;
    Node(int val,vector<int> path) {
        this->val = val;
        this->path = path;
    }
    
    Node() {
        this->path = vector<int>();
        this->val = 0;

    }

    void addChild(Node n) {
        this->children.push_back(n);
    }

};

class Solution {
public:
    void coinChange2(int amount,vector<int> coins) {
        // start with amoun5
        // 5
        // 4 3 0
        // 0 returns and increments # of combinations
        std::cout << amount << std::endl;
        stack<Node> myStack;
        myStack.push(Node(amount,vector<int>()));
        Node currentNode;
        std::set<vector<int>> pathSet;
        std::cout << myStack.empty() << std::endl;
        while(!myStack.empty()) {
            std:: cout << "RUNNING LOOP" << std::endl;
            currentNode = myStack.top();
            myStack.pop();
            for(int i: coins) {
                if(currentNode.val-i > 0) {
                    std::cout << "> 0" << currentNode.val-i << std::endl;
                    int newval = currentNode.val-i;
                    vector<int> newpath = currentNode.path;
                    newpath.push_back(i);
                    myStack.push(Node(newval,newpath));
                }
                else if(currentNode.val-i == 0) {
                    std::cout << "== 0" << currentNode.val-i << std::endl;
                    vector<int> newpath = currentNode.path;
                    newpath.push_back(i);
                    std::sort(newpath.begin(),newpath.end());
                    
                    if(pathSet.count(newpath) == 0) {
                        pathSet.insert(newpath);
                        std::cout << "NEW PATH" << std::endl;
                        printvec(newpath);
                    }
                    else {
                        std::cout << "NO NEW PATH" << std::endl;
                    }

                    
                }
                else {
                    // if < 0, do nothing

                }
            }
            
        }
        std::cout << "COMBINATIONS: " << pathSet.size() << std::endl;
        
    }

};


int main()
{
    Solution x;
    x.coinChange2(5,std::vector{1,2,5});
    return 0;
}