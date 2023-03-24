#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {

        unordered_map<int, int> freqMap;
        vector<int> taskVec;

        for (int i = 0; i < tasks.size(); i++) {
            if (freqMap.find(i) == freqMap.end()) {
                freqMap[i] = 1;
                taskVec.push_back(i);

            } else {
                freqMap[i]++;
            }
        }
        int minRoundsTotal = 0;
        for(int i = 0; i < taskVec.size(); i++) {
            int minRounds = minRoundsForTask(taskVec[i]);
            if (minRounds == -1) return -1;
            else minRoundsTotal += minRounds;
        }

        return minRoundsTotal;


    }
    int minRoundsForTask(int taskFrequency) {
        if(taskFrequency == 1) return -1;
        else if(taskFrequency == 0) return 0;
        else if(taskFrequency%3 == 0) return taskFrequency/3;
        else {
            // Divide into 3s and 2s
            int maxThrees = taskFrequency/3;
            int remainder = taskFrequency%3;
            if(remainder%2 == 0) return maxThrees + remainder/2;
            else {
                if(maxThrees-1 > 0) {
                    maxThrees--;
                    remainder+=3;
                    return maxThrees + remainder/2;
                }
                else {
                    return -1;
                }
            }
        }
    }
};