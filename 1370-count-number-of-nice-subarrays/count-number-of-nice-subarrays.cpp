class Solution {

private:
  
  int atMost(vector<int>&nums,int k){
     if(k<0) return 0;


     int left =0;
     int totalSubarrays =0;
     int oddCount =0;

     for(int right =0;right <nums.size();right++){
        if(nums[right] %2 !=0){
            oddCount++;
        }

        while(oddCount >k){
            if(nums[left] % 2 !=0){
                oddCount --;
            }
            left++;
        }
        totalSubarrays += (right - left +1);
        
     }
     return totalSubarrays;
  }

public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        return atMost(nums,k) - atMost(nums,k-1);
    }
};