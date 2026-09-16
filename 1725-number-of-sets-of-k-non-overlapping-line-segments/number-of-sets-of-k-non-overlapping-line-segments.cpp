class Solution {

    const int MOD = 1e9+7;

    int solve(int n,int i, int k, int isbuilding,vector<vector<vector<int>>>&dp){
        if( k == 0 ) return 1;

        if(i >= n) return 0;

        if(dp[i][k][isbuilding] != -1 ) return dp[i][k][isbuilding];

        long long ans = 0;
         if(isbuilding == 0){
            
            long long skip = solve(n,i+1,k,0,dp);
            long long extend = solve(n,i+1,k,1,dp);
            
            ans = (skip+extend)%MOD;
         }
         else{
             
             long long end = solve(n,i,k-1,0,dp);
             long long extend = solve(n,i+1,k,1,dp);

             ans  = (end+extend)%MOD;
         }

         return dp[i][k][isbuilding] = ans ;
    }

    
public:
    int numberOfSets(int n, int k) {

      vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(k+1,vector<int>(2,-1)));

        return solve(n,0,k,0,dp);
      
    }
};