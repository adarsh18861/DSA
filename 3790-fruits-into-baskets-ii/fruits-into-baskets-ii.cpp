class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        
        int n = baskets.size();
        vector<bool> full(n,false);

        int ans =0;

        for(int i=0;i<fruits.size();i++){
           
           int j =0;
            while(!(!full[j] && baskets[j] >= fruits[i])){
                j++;
                if(j>=n) break;
            }
            
            if(j<n){
                 full[j] = true;;
            }
            else{ ans+=1;
            }
           
        }

        return ans;
    }
};