class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        
        vector<pair<int,int>> vec;

        auto lambda = [](pair<int,int>&a,pair<int,int>&b){

            return a.first > b.first;
        };

        for(int i=0;i<nums1.size();i++){
            vec.push_back({nums2[i],nums1[i]});
        }

        sort(vec.begin(),vec.end(),lambda);

        long long k_sum =0;
        long long  ans =0;

      priority_queue<int,vector<int>,greater<int>>pq;
   
        for(int i=0;i<= k-1;i++){
            k_sum += vec[i].second;
            pq.push(vec[i].second);
        }
        ans = k_sum*vec[k-1].first;
      
        int i= k ;
        

        while(i < nums1.size()){
          
        
            k_sum += vec[i].second - pq.top();
            pq.pop();
            pq.push(vec[i].second);
              ans = max(ans,k_sum*vec[i].first);
        

        

          i++;


        }

        return ans;
        
    }

};