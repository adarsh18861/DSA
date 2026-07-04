class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n= deck.size();
        bool skip = false;
        vector<int>result(n,0);

        int i=0;
        int j=0;

        sort(begin(deck),end(deck));

        while(i<n){
            if(result[j] == 0){
                if(skip == false){
                   result[j] = deck[i];
                   i++;
                }
                skip = !skip;
            }
            j = (j+1)%n;
        }  

        return result; 
    }
};  