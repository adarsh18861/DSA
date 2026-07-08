class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        
      

        priority_queue<int> p;

        for( int num : nums){

            p.push(num);
        }
        
         long long  score =0;
        while(k>0 && !p.empty()){
            
            int m = p.top();
            p.pop();
            score += m;

            m = (m+2)/3;
            if(m >0){
            p.push(m);
            }
            k--;
            
        }

        return score;
    }
};