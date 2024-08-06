#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int target;
    int total;
    vector<int> nums;
    map<pair<int,int>,int> possibilityMap = {};
    int findTargetSumWays(vector<int>& nums, int target) {
        this->target = target;
        this->nums = nums;
        this->possibilityMap = {};
        this->total = 0;
        for(int i = 0; i < nums.size(); i++) {
            total+=nums[i];
        }
        /*
        
                                (0)
                +1                               -1
                (1)                              (-1)
            +1      -1                      
           
            - 1
        */


        /*
            at each step we make a decision to either take or not take the number
            possibilities = fts()
        
        
        */
        return this->findPossibilities(0,0);
    }
    int findPossibilities(int index,int current) {

        if(this->possibilityMap.find({index,current}) != this->possibilityMap.end()) return this->possibilityMap[{index,current}];
        int possibilities = 0;
        // if we've gone past the point of no return with the decision tree;
        // 
        // if(abs(current-total) > abs(total) && index > 0) {
        //     cout << "past the point of no return: " << index << " " << current <<  endl;
        //     this->possibilityMap[{index,current}] = 0;
        //     return 0;
        // }

        // if we've reached the target, yay add a possibility
        if(current == this->target && index == this->nums.size()) {
            // cout << "Imagine if I had a real weapon " << endl;
            this->possibilityMap[{index,current}] = 1;
            return 1;
        }
            // we've reached the end of the road, but the target has not been reached; warn others
        else if(index == this->nums.size()) {
            // cout << "End of the road, pardner. " << index << " " << current << endl;
            this->possibilityMap[{index,current}] = 0;
            return 0;
        }
        else {

            possibilities = findPossibilities(index+1,current-nums[index]) + findPossibilities(index+1,current+nums[index]);
            this->possibilityMap[{index,current}] = possibilities;
            return possibilities;
        }
    }
};