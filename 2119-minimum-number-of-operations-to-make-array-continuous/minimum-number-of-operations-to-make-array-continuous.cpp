class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        int n = nums.size();

        sort(nums.begin(),nums.end());

        vector<int>uniqueNums;
        for(int num :nums){
            if(uniqueNums.empty() || num != uniqueNums.back()){
                uniqueNums.push_back(num);
            }
        }
        int minOps = n;
        int m = uniqueNums.size();
        int right =0;

        for(int left =0;left<m;left++){
            int L = uniqueNums[left];
            int R = L +n-1;

            while(right <m && uniqueNums[right] <= R){
                right++;
            }

            int validcount = right-left;

            minOps = min(minOps,n-validcount);
        }

        return minOps;
    }
};