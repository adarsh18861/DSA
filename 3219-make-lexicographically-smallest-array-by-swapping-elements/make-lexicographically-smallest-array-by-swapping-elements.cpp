class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        
        int n = nums.size();

        vector<int> vec;
        vec = nums;

        sort(vec.begin(),vec.end());

        int groupnum =0;
        unordered_map<int,int>numtogroup;
        numtogroup[vec[0]] = 0;
        unordered_map<int,list<int>>grouptolist;
        grouptolist[0].push_back(vec[0]);

        for(int i=1;i<n;i++){

            if(vec[i] -vec[i-1] > limit){
                groupnum++;
            }

            int num = vec[i];
            numtogroup[num] = groupnum;
            grouptolist[groupnum].push_back(num);
        }
        vector<int>result(n);
        for(int i=0;i<n;i++){
            int num = nums[i];
            int group = numtogroup[num];

            result[i] = *(grouptolist[group].begin());
            grouptolist[group].pop_front();
        }

        return result;
    }
};