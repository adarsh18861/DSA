class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum =0;

        for(int num : nums){
            sum += num;
        }

        if(sum % 2  != 0){
             return false ;
        }

        int target = sum/2;
        int n = nums.size();
        vector<vector<bool>> dp(n+1,vector<bool>(target+1,false));

        for(int i=0;i<=n;i++){
            dp[i][0] = true;
        }

        for(int i=1;i<=n;i++){
            int currentNum = nums[i-1];
            for(int j=1;j<= target;j++){
                bool exclude = dp[i-1][j];

                bool include = false;
                if(j >= currentNum){
                    include = dp[i-1][j- currentNum];
                }

                dp[i][j] = exclude || include;
            }
        }
     
     return dp[n][target];
    }
};