class Solution {
public:
    bool canPartition(const vector<int> &num, int sum) {
        int numSum;
        for(int i = 0; i < num.size(); i++) {
            numSum+=num[i];
        }
        if(numSum == sum) return true;
        if(numSum < sum) return false;


        vector<vector<int>> dp(num.size(), vector<int>(numSum, -1));

        return canPartitionRecursive(dp,num,sum,0);
    }

    bool canPartitionRecursive(vector<vector<int>>& dp, vector<int> num, int sum, int i) {
        if(sum == 0) {
            dp[i][sum] = 1;
        };
        // if we haven't processed a similar problem yet
        if(dp[i][sum] == -1) {
            // If the number we're processing is greater than our target sum, we need to ignore this number
            if(num[i] < sum) {
                dp[i][sum] = canPartitionRecursive(dp,num,sum-num[i],i+1);
            }
            else if(num[i] == sum) {
                dp[i][sum] = 1;
            }
            else {
                // calculate the next one over instead, if it exists. if it does not exist, set dp[i][sum] to false
                if(i+1 < num.size()){
                    dp[i][sum] = canPartitionRecursive(dp, num,sum,i+1);
                }
                else {
                    dp[i][sum] = 0;
                }
            }
        }
        return dp[i][sum] == 1 ? true : false;

    }
};
