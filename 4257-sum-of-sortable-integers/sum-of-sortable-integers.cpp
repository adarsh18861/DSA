class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
      

    //    int n = nums.size();
    //     vector<int> s = nums;
    //     sort(s.begin(), s.end());
        
    //     long long total_sum = 0;
        
    //     vector<int> double_block;
    //     double_block.reserve(2 * n);
    //     vector<int> lps;
    //     lps.reserve(n);
        
    //     for (int k = 1; k <= n; ++k) {
    //         if (n % k != 0) continue;
            
    //         bool possible = true;
    //         for (int i = 0; i < n; i += k) {
    //             double_block.resize(2 * k);
    //             for (int j = 0; j < k; ++j) {
    //                 double_block[j] = nums[i + j];
    //                 double_block[k + j] = nums[i + j];
    //             }
                
    //             lps.resize(k);
    //             lps[0] = 0;
    //             int len = 0;
    //             int idx = 1;
    //             while (idx < k) {
    //                 if (s[i + idx] == s[i + len]) {
    //                     len++;
    //                     lps[idx] = len;
    //                     idx++;
    //                 } else {
    //                     if (len != 0) {
    //                         len = lps[len - 1];
    //                     } else {
    //                         lps[idx] = 0;
    //                         idx++;
    //                     }
    //                 }
    //             }
                
    //             int j_pat = 0;
    //             int i_text = 0;
    //             bool found = false;
                
    //             while (i_text < 2 * k) {
    //                 if (s[i + j_pat] == double_block[i_text]) {
    //                     i_text++;
    //                     j_pat++;
    //                 }
                    
    //                 if (j_pat == k) {
    //                     found = true;
    //                     break;
    //                 } else if (i_text < 2 * k && s[i + j_pat] != double_block[i_text]) {
    //                     if (j_pat != 0) {
    //                         j_pat = lps[j_pat - 1];
    //                     } else {
    //                         i_text++;
    //                     }
    //                 }
    //             }
                
    //             if (!found) {
    //                 possible = false;
    //                 break;
    //             }
    //         }
            
    //         if (possible) {
    //             total_sum += k;
    //         }
    //     }
        
    //     return total_sum;

     int n = nums.size();
        vector<int> s = nums;
        sort(s.begin(), s.end());
        
        long long total_sum = 0;
        
        for (int k = 1; k <= n; ++k) {
            if (n % k != 0) continue;
            
            bool possible = true;
            for (int i = 0; i < n; i += k) {
                int drops = 0;
                for (int j = 0; j < k; ++j) {
                    if (nums[i + j] > nums[i + (j + 1) % k]) {
                        drops++;
                    }
                }
                
                if (drops > 1) {
                    possible = false;
                    break;
                }
                
                vector<int> block(nums.begin() + i, nums.begin() + i + k);
                sort(block.begin(), block.end());
                
                bool match = true;
                for (int j = 0; j < k; ++j) {
                    if (block[j] != s[i + j]) {
                        match = false;
                        break;
                    }
                }
                
                if (!match) {
                    possible = false;
                    break;
                }
            }
            
            if (possible) {
                total_sum += k;
            }
        }
        
        return total_sum;
    }
};