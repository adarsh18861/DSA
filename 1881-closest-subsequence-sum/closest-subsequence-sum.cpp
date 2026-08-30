class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        
        int n = nums.size();

        if (n == 1) return min(abs((long long)goal),abs((long long)goal - nums[0]));

        int n1 = n / 2;
        int n2 = n - n1;

        vector<long long> subsA(1 << n1, 0);
        vector<long long> subsB(1 << n2, 0);

        for (int i = 0; i < (1 << n1); i++) {
            for (int j = 0; j < n1; j++) {
                if (i & (1 << j)) subsA[i] += nums[j];
            }
        }

        for (int i = 0; i < (1 << n2); i++) {
            for (int j = 0; j < n2; j++) {
                if (i & (1 << j)) subsB[i] += nums[n1 + j];
            }
        }

        sort(subsB.begin(), subsB.end());
        long long ans = LLONG_MAX;

        for (size_t i = 0; i < subsA.size(); i++) {
            long long need = (long long)goal - subsA[i];
            
            auto lo = lower_bound(subsB.begin(), subsB.end(), need);
          
            if (lo != subsB.end()) {
                int idx = lo - subsB.begin();
                ans = min(ans, abs(subsB[idx] - need));

                if (idx - 1 >= 0) {
                    ans = min(ans, abs(subsB[idx - 1] - need));
                }
            } else {
                ans = min(ans, abs(subsB.back() - need));
            }
        }

        return static_cast<int>(ans);
    }
};