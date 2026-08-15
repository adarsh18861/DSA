class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        
        vector<int>freq1(31,0);
        vector<int>freq2(31,0);
        int n = nums.size();

        for(int i=0;i<n;i++){

            int num = nums[i];
            for(int j=0;j< 31;j++){
               
                    if(num&1){
                     freq2[j]++;
                    }
                    else{
                       freq1[j]++;
                    }
                    num = num>>1;
                  }
              
              
            }
        

        int ans =0;

        for(int i=0;i<31;i++){

            if(freq2[i]%2 == 0 && freq2[i] >0){
                ans = max(ans,freq1[i]+freq2[i]-1);
            }

            else if(freq2[i] > 0){
                ans = max(ans,freq1[i] + freq2[i]);
            }
        }

        return ans ;



    }
};