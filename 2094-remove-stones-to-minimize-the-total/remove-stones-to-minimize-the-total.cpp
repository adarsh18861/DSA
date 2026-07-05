class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        
        priority_queue<int>p;

        for( int pile :piles){
            p.push(pile);
        }

        while(k!=0){
            int temp = p.top();
            p.pop();

            temp = (temp+1)/2;
            p.push(temp);
            k--;
        }

        int ans =0;

        while(!p.empty()){
            ans += p.top();
            p.pop();

        }

        return ans;
    }
};