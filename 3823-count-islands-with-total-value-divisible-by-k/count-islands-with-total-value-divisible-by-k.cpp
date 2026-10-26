class Solution {

  int solve(vector<vector<int>>& grid,int i,int j,int r, int c,int k){
       
       if(i >= r || j >= c || i< 0 || j<0 ||grid[i][j] == 0) return 0;
       int sum = grid[i][j]%k;
       grid[i][j] =0;
       
       sum = (sum + solve(grid,i+1,j,r,c,k))%k;
       sum  =(sum + solve(grid,i,j+1,r,c,k))%k;
       sum   =  (sum + solve(grid,i-1,j,r,c,k))%k;
       sum = (sum + solve(grid,i,j-1,r,c,k))%k;

       return sum;
       
       
  }

public:
    int countIslands(vector<vector<int>>& grid, int k) {
         int r = grid.size();
         int c = grid[0].size();

         int ans =0;

         for(int i=0;i<r;i++){
            for(int j =0;j<c;j++){
                if (grid[i][j] == 0) continue;
                 if(solve(grid,i,j,r,c,k)%k == 0) ans++;
            } 
         }

         return ans;
    }
};