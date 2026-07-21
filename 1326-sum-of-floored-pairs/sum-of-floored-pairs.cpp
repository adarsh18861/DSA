#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int sumOfFlooredPairs(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int maxVal = 0;
        for (int num : nums) {
            maxVal = max(maxVal, num);
        }

        // Step 1: Compute frequency array
        vector<int> freq(maxVal + 1, 0);
        for (int num : nums) {
            freq[num]++;
        }

        // Step 2: Compute prefix sums of frequency array
        vector<int> pref(maxVal + 1, 0);
        for (int i = 1; i <= maxVal; i++) {
            pref[i] = pref[i - 1] + freq[i];
        }

        long long totalSum = 0;

        // Step 3: Iterate through all possible denominator values y
        for (int y = 1; y <= maxVal; y++) {
            if (freq[y] == 0) continue;

            long long currentYSum = 0;

            // Check range [k*y, (k+1)*y - 1] for each multiplier k
            for (int k = 1; k * y <= maxVal; k++) {
                int L = k * y;
                int R = min(maxVal, (k + 1) * y - 1);

                // Count elements in range [L, R]
                long long count = pref[R] - pref[L - 1];

                // Contribution = k * count
                currentYSum = (currentYSum + k * count) % MOD;
            }

            // Multiply contribution by frequency of denominator y
            totalSum = (totalSum + currentYSum * freq[y]) % MOD;
        }

        return totalSum;
    }
};