#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <set>
#include <algorithm>
using namespace std;

/*
Longest Substring Without Repeating Characters
------------------------------
Given a string, find the length of the longest substring without
repeating characters.
Examples:
Given "abcabcbb", the answer is "abc", which the length is 3.
Given "bbbbb", the answer is "b", with the length of 1.
Given "pwwkew", the answer is "wke", with the length of 3. Note that
the answer must be a substring, "pwke" is a subsequence and not a
substring.
----------------

*/

class Solution {
    public:
         string longestSubstringWithoutRepeatingCharacters(string inp) {
            
            // brute force-ish solution
            // sliding window
            string currentString = "";
            unordered_map<char,bool> currentMap;
            for(char c:inp) {
                // if the current character IS in the map, we need to a
                if(currentMap.find(c) != currentMap.end()) {
                    currentString = 

                }
            }

            return "";
        }

};



int main() {

    string in = "abcabcbb";
    Solution x;
    x.longestSubstringWithoutRepeatingCharacters(in);

    return 0;
}