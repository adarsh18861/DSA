class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        
         deque<int>maxDq;
         deque<int>minDq;

         int left =0;
         int maxLen =0;

         for(int right =0;right< nums.size();right++){

            while(!maxDq.empty() && maxDq.back() < nums[right]){
                maxDq.pop_back();
            }
            maxDq.push_back(nums[right]);

            while(!minDq.empty() && minDq.back() > nums[right]){
                minDq.pop_back();

            }

            minDq.push_back(nums[right]);

            while(maxDq.front() - minDq.front()> limit){
                if(maxDq.front() == nums[left]){
                    maxDq.pop_front();
                }

                if(minDq.front() == nums[left]){
                    minDq.pop_front();
                }
                left++;
            }

            maxLen = max(maxLen,right-left+1);
         }
         return maxLen;
    }
};