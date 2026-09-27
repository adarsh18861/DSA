class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int maxi = INT_MIN;
        int n = nums.size();

        for(int i=0;i<n;i++){
            maxi = max(maxi,nums[i]);
        }

        int m = maxi/k;

        for(int i=1;i<=m;i++){
            int num = k*i;
            bool pre = false;
            for(int i=0;i<n;i++){
                if(nums[i] == num) {
                    pre = true;
                    break;
                }
            }
            if(! pre) return num;
        }

        return (m+1)*k;
    }
};