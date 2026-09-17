class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
          
          int n = arr.size();
          vector<int>prefix(n,0);
          prefix[0] = arr[0];

          for(int i=1;i<n;i++){
            prefix[i] = arr[i] + prefix[i-1];
          }

          vector<int>len(n,INT_MAX);
          for(int i =0;i<n;i++){
             int t = prefix[i] - target;

             if(t < 0 ) continue;
             else if (t == 0) len[i] = i+1;

             else{
                int low = 0;
                int high = i-1;
                int mid ;
                while(low <= high ){
                    mid = low + (high - low)/2;

                    if(prefix[mid] < t) low = mid+1;
                    else if(prefix[mid] > t) high = mid-1;

                    else {
                        len[i] = i-mid;
                        break;
                    }
                }
             }
          }

          vector<int> mini(n,INT_MAX);
          int m = INT_MAX;

          for(int i=0;i<n;i++){
            mini[i] = min(m,len[i]);
            m = min(m,mini[i]);
          }

          int ans = INT_MAX;

          for(int i =1;i<n;i++){
            if(len[i] != INT_MAX){ 
                    if(i-len[i] >= 0){
                        if(mini[i-len[i]]!= INT_MAX){
                            ans = min(ans, len[i] + mini[i-len[i]] );
                        }
                    }
              }
          }
        if(ans == INT_MAX) return -1;

        return ans;
    }
};