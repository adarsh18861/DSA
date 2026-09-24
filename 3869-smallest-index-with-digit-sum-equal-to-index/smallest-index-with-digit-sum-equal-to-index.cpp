class Solution {
public:
    int smallestIndex(vector<int>& nums) {
         
         int n = nums.size();
         for(int i =0;i<n;i++){
              
              int dsum =0;

              int num = nums[i];
              while(num!=0){
                 dsum += num%10;
                 num /= 10;
              }

              if( dsum == i) return i;
         }

         return -1;
    }
};