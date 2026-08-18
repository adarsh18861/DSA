class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int ans1 = nums[0];
        int ans2 = nums[n-1];

        int freq1 =0;
        int freq2 =0;
        int ovmax = -1;
       
       unordered_map<int,int>freq;
        for(int i=0;i<n;i++){
            ovmax = max(ovmax,nums[i]);
            if(nums[i] == nums[0]) freq1++;
            if(nums[i] == nums[n-1]) freq2++;

            freq[nums[i]]++;
        }

        if( k == n) return ovmax;

        if( k ==1){
            int ans = -1;
             
            for(auto [num,fre] : freq){
               if(fre == 1) ans = max(ans,num);
            } 
            return ans;
        }

        if(freq1==1 && freq2 == 1){
            return max(ans1,ans2);
        }

        // return -1;

        if (freq1 == 1) return ans1;

        if( freq2 == 1) return ans2;

        return -1;


    }
};