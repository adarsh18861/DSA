class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int>dp(n);
        deque<int> dq;

        int maxSubsequencesum = nums[0];

        for(int i=0;i<n;i++){
            if(!dq.empty() && dq.front() < i-k){
                dq.pop_front();
            }

            int maxPrevious = dq.empty()?0:max(0,dp[dq.front()]);

            dp[i]  = nums[i] + maxPrevious;
            maxSubsequencesum = max(maxSubsequencesum,dp[i]);

            while(!dq.empty() && dp[dq.back()] <= dp[i]){
                dq.pop_back();
            }

            dq.push_back(i);
        }

        return maxSubsequencesum;
    }
};