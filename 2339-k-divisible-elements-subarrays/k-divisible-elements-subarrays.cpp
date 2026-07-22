class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        
        int n = nums.size();
        set<vector<int>>uniqueSubarrays;

        for(int i=0;i<n;i++){
            int divcount =0;
            vector<int> csa;

            for(int j = i;j<n;j++){
                if(nums[j]%p == 0){
                    divcount ++;
                }
                if(divcount >k){
                    break ;
                }

                csa.push_back(nums[j]);
                uniqueSubarrays.insert(csa);
            }
        }
        return uniqueSubarrays.size();
    }
};