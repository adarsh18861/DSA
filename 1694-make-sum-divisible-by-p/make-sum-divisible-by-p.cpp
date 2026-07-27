#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        
        // Total sum ka remainder nikal lo safely (bina long long overflow ke)
        int rem = 0;
        for (int num : nums) {
            rem = (rem + num) % p;
        }
        
        // Agar pehle se hi divisible hai, kuch remove nahi karna
        if (rem == 0) return 0;
        
        // Map stores -> Prefix Modulo : Latest Index
        unordered_map<int, int> prefixModMap;
        prefixModMap[0] = -1; // Base case
        
        int currentSum = 0;
        int min_len = n;
        
        for (int i = 0; i < n; i++) {
            currentSum = (currentSum + nums[i]) % p;
            
            // Equation to find the target prefix mod we need to remove
            int target = (currentSum - rem + p) % p;
            
            // Agar target map mein mil gaya
            if (prefixModMap.count(target)) {
                // Minimum length update karo
                min_len = min(min_len, i - prefixModMap[target]);
            }
            
            // Current mod ko map mein latest index ke sath store kar do
            prefixModMap[currentSum] = i;
        }
        
        // Agar subarray length array ke barabar ho gayi toh valid nahi hai
        return min_len == n ? -1 : min_len;
    }
};