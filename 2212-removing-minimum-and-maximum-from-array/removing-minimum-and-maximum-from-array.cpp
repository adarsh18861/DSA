class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        
        int n = nums.size();


        if( n == 1 || n == 2) return n; 

        int mini =INT_MAX;
        int maxi = INT_MIN;

        int minidx;
        int maxidx;
        for(int i=0;i<nums.size();i++){

            if(nums[i] < mini){
                mini = nums[i];
                minidx =i;
            }

            if(nums[i] > maxi){
                maxi = nums[i];
                maxidx = i;
            }
        }

        int ans = INT_MAX;

        int indx = max(minidx,maxidx);
        int iindx = min(minidx,maxidx);

        ans = min(ans,indx+1);

        ans = min(ans ,(iindx+1)+(n-indx));

        ans = min(ans,n-iindx);

        return ans;

    }
};