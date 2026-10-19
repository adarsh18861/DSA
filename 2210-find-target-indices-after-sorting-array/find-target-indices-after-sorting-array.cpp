class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        
          int count =0;
          int less =0;
          
          for(int i=0;i<nums.size();i++){
             if(nums[i] == target) count ++;

             if(nums[i]< target) less++;
          }

          vector<int>result;

          if(count > 0){
            for(int i=less;count>0;count--,less++){
                result.push_back(less);
            }
          }

          return result;
    }
};