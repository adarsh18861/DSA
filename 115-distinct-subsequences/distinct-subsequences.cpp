class Solution {

    int solve(string&s,string&t, int i,int j, vector<vector<int>>&dp,int m,int n){
         if(j == m) return 1;

         if(i == n) return 0;

         if(dp[i][j] != -1) return  dp[i][j];

         if(s[i] == t[j]){
            dp[i][j] = solve(s,t,i+1,j+1,dp,m,n) + solve(s,t,i+1,j,dp,m,n);
         }
         else{
            dp[i][j] = solve(s,t,i+1,j,dp,m,n);
         }

         return dp[i][j];
    }

public:
    int numDistinct(string s, string t) {
        
        int n = s.length();
        int m = t.length();

        vector<vector<int>>dp(n+1,vector<int>(m,-1));
        return solve(s,t,0,0,dp,m,n);

    }
};