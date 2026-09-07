class Solution {
    const int MOD = 1e9 +7;
public:
    int distinctSubseqII(string s) {
        
        int n = s.length();

        vector<int>dp(n,0);
        
        
        vector<int> freq(26,0);
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }
        for(int i = 0;i<n;i++){
            if(freq[s[i]-'a']>0)dp[i]=1;
            freq[s[i]-'a']=0;
        }

        for(int i=1;i<n;i++){
           
            for(int j = i-1;j>=0;j--){
               dp[i] = (dp[i]+dp[j])%MOD;
               if(s[i] == s[j]){
                 break;
               }
            }
        }
 
        int ans =0;
        
       
        for(int i=0;i<n;i++){
            ans = (ans+dp[i])%MOD;
        }

        return ans;
    }

};