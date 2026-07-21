class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {

     int n = nums.size();

     vector<int> pre(n+1,0);

     for(int i=0;i<n;i++){
        pre[i+1] = pre[i] + nums[i];
     }  

     deque<int> dq;

     int minlen = n+1;

     for(int j=0;j<=n;j++){
        
        while(!dq.empty() && pre[j] - pre[dq.front()] >= k){
            minlen = min(minlen,j-dq.front());
            dq.pop_front();
        }

        while(!dq.empty() && pre[j]<= pre[dq.back()]){
            dq.pop_back();
        }

        dq.push_back(j);
     } 

     return(minlen <= n)? minlen : -1;
    }
};