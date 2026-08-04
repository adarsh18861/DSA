class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();

        int offset  = 1000;
        int sum =0;
        for(int num:nums){
            sum += num;
        }

        if(target > sum ) return 0;

        vector<vector<int>>dp(n+1,vector<int>(2001,0));
        dp[0][offset -nums[0]] += 1;
        dp[0][offset+nums[0]] += 1;

        for(int i=1;i<n;i++){

            for(int j =0;j <= 2000;j++){
               
               if(j+nums[i] <= 2000){
                dp[i][j] = dp[i-1][j+nums[i]];
               }

                if(j-nums[i] >=0){
                    dp[i][j] += dp[i-1][j-nums[i]];
                }
            }
        }

        return dp[n-1][target+offset];
    }
};