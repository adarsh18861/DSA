class Solution {
public:

    void find_lps(string & word,vector<int>&lps,int n){

        lps[0] =0;
        int i=1;
        int len =0;
        while(i<n){

            if(word[i] == word[len]){
                len++;
                lps[i] = len;
                i++;
            }
            else{
                if(len >0){
                    len = lps[len-1];
                }
                else{
                    lps[i]=0;
                    len =0;
                    i++;
                }
            }
        }
    }
    int minimumTimeToInitialState(string word, int k) {
        
        int n = word.length();
        vector<int>lps(n,0);

        find_lps(word,lps,n);

        int ans =0;
        int pre = lps[n-1];

        while((n-pre)%k !=0 && pre>0){
            if(pre > 0){
                pre = lps[pre-1];
            }
        }

        if((n-pre)%k == 0) ans = (n-pre)/k;
        else ans = (n-pre)/k +1;

        return ans; 
    }
};