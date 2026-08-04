#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        
        int sum =0;
        for(int x: rods){
            sum += x;
        }

        vector<int>dp(sum +1,-1);
        dp[0] =0;
        

        for( int r : rods){
            vector<int> next_dp = dp;

            for(int diff =0;diff <= sum ;diff++){
                if(dp[diff] == -1) continue;

                int h_short = dp[diff];

                if(diff+r <= sum){
                    next_dp[diff+r] = max(next_dp[diff +r],h_short);
                }

                int newdiff = abs(diff - r);
                h_short = h_short + min(diff,r);
                next_dp[newdiff] = max(next_dp[newdiff],h_short);

            }

            dp = next_dp;
        }
       
        return dp[0];
    }
};