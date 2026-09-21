class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
         vector<long long> result(k, 0);
        unordered_map<int, long long> current_dp;

        for (int num : nums) {
            unordered_map<int, long long> next_dp;
            
            int single_rem = num % k;
            next_dp[single_rem] += 1;
            
            for (const auto& pair : current_dp) {
                int prev_rem = pair.first;
                long long count = pair.second;
                
                int new_rem = (1LL * prev_rem * num) % k;
                next_dp[new_rem] += count;
            }
            
            current_dp = next_dp;
            
            for (const auto& pair : current_dp) {
                result[pair.first] += pair.second;
            }
        }
        
        return result;
    }
};