#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

void printvec(vector<string> v, char digit) {
    std::cout << "PRINTVEC " << digit <<  std::endl;
    for(auto i: v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        // build a dictionary of what each digit is in terms of its available letters  
        // process each individual letter from a single digit; call a recursive "get combinations" on that, where it appends the possible combinations from that digit to a list of strings, and then returns that list. input will be current string
        unordered_map<char,vector<char>> letterMap;
        letterMap['2'] = vector<char>{'a','b','c'};
        letterMap['3'] = vector<char>{'d','e','f'};
        letterMap['4'] = vector<char>{'g','h','i'};
        letterMap['5'] = vector<char>{'j','k','l'};
        letterMap['6'] = vector<char>{'m','n','o'};
        letterMap['7'] = vector<char>{'p','q','r','s'};
        letterMap['8'] = vector<char>{'t','u','v'};
        letterMap['9'] = vector<char>{'w','x','y','z'};
        
        vector<string> combinations = vector<string>{""};
        vector<string> newcombinations;
        for(auto &digit: digits) {
            //std::cout <<digit << std::endl;
            vector<string> newcombinations;
            for(auto &combination:combinations) {
              //  std::cout << combination << std::endl;
               
                for(auto letter:letterMap[digit]) {
                   
                    std::cout << "COMBINATION + LETTER: " << combination + letter << std::endl;
                                    newcombinations.push_back(combination + letter);
                  //  std::cout << (combination + letter) << std::endl;
                }
            }
            printvec(newcombinations,digit);
            combinations = newcombinations;
        }
        return combinations;
        
    }
    /*
    vector<string> newcombinations(string currentString,vector<char> letters) {
        vector<string> combinations;
        for(auto &ch: letters) {
            combinations.push_back(currentString+ch)
        }
        return combinations
    }
    */
};


int main()
{
    Solution x;
    vector<string> res;
    res = x.letterCombinations("23");
    for(auto i: res) std::cout << i << std::endl;
}