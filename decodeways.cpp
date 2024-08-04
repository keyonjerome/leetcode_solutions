#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    unordered_map<int,int> solMap;
    string inputString;
    int numDecodings(string s) {
        this->solMap = {{s.size(),1}};
        this->inputString = s;



        return dfs(0);
        /*
            '1' -> 'A'
            ...
        */

        /*
        
        "11106" -> "1"+  "1106", or "11" + "106"
        
        brute force
        look at number i and i+1
        we are not concerned with what messages they map to, as we only carea bout the number of ways to decode it
        we look at number i and i+1 and convert it to a pattern as follows:
        if there are no characters left, return
        else if if there are at least two characters left:
            we need to calculate the number of possible ways to decode it from there
            if int(str(i)+str(i+1)) <<= 26 and str(i) != '0' then we have two ways of decoding it
            else if str(i) == '0' naw we cant do this one, a 0 on its own fails
            else we only have one way (we need to take the single first character, then decode it again recursively)
        else there is only one character left
            res*1
        
        */

    }

    // i is index
    int dfs(int i) {
        if(this->inputString[i] == '0') return 0;
        // cout << "dfs on " << i << endl;
        int res = 0;
        // if in map, return
        if(this->solMap.find(i) != solMap.end()) {
            // cout << "Returning " <<  solMap[i] << " from map" << endl;
            return solMap[i];
        }
        // if not in map, we need to find out what the strings next two characters are

        // handle the single character case;
        res = dfs(i+1);
        // handle the potential second character case
        // cout << "i: " << i << " inputString[i]: " << this->inputString[i]  << endl;
        // cout << (i+1 < this->inputString.size()) << (static_cast<char>(this->inputString[i]) == '1') << " | " <<  static_cast<char>(this->inputString[i])  << " " << static_cast<int>(this->inputString[i+1]) << endl;
        if(i+1 < this->inputString.size() && (static_cast<char>(this->inputString[i]) == '1' || (static_cast<char>(this->inputString[i]) == '2' && (int)(this->inputString[i+1] - '0') <= 6))) {
            // cout << "Handling second character case" << endl;
            res+= dfs(i+2);
        }
        // cout << "dfs(" << i << ")" << " : " << res << endl;
        this->solMap[i] = res;
        return res;
    }
};
