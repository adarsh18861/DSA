class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int n = nums.size();
        vector<int> prefix(n+1,0);
        int totalsum = nums[0];
        
        prefix[0] = nums[0];
        for(int i=1;i<n;i++){
            prefix[i]  = nums[i]+prefix[i-1];
            totalsum += nums[i];
        }
        

        int mop =  INT_MAX;

        for(int i=n;i>0;i--){

            int target = x-(totalsum - prefix[i-1]);

            if(target == 0) {
                mop = min(mop,n-i);
                continue;
            }

            else if(target <0) break;

            int low = 0;
            int high = i-1;

            while(low <= high){
                int mid = low + (high -low)/2;

                if(prefix[mid] < target) low = mid+1;

                else if (prefix[mid] > target) high = mid-1;

                else  {
                    mop = min(mop,mid+n-i+1);
                    break;
                 }
            }
        }

        if(mop == INT_MAX) return -1;

        return mop;
    }
};