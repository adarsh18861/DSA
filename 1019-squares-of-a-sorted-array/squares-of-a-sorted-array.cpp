class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
       
       int n = nums.size(); 
       vector<int>result(n);
       

       int l =0;
       int r= n-1;
       int j = n-1;

       while( l <= r){
         int lsq = nums[l]*nums[l];
         int rsq = nums[r]*nums[r];

         if(lsq <= rsq){
            result[j] = rsq;
            r--;
            j--;
         }
         else{
            result[j] = lsq;
            l++;
            j--;
         }
       }
     

       return result;
    }
};