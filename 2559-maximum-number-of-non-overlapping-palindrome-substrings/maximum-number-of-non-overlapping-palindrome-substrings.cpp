class Solution {
public:
    int maxPalindromes(string s, int k) {
        
        int n = s.length();

        vector<vector<bool>>ispalindrome(n+1,vector<bool>(n+1,false));
         
         for(int l=1;l<=n;l++){
            for(int i=0;i+l<=n;i++){
                 int j = i+l-1;

                 if(i == j) ispalindrome[i][j] = true;
                 else if(i+1 == j) {
                     if(s[i] == s[j]) ispalindrome[i][j] = true;
                 }

                 else{
                    if(s[i] == s[j] && ispalindrome[i+1][j-1]){
                        ispalindrome[i][j] = true;
                    }
                 }

            }
         }

         vector<vector<int>>t(n+1,vector<int>(n+1,0));
      
         for(int i= n-1;i>=0;i--){
            for(int j= n-1;j>=0;j--){
                if(ispalindrome[i][j]){
                    int take =  1+(j+k<n? t[j+1][j+k]:0);
                    int grow = t[i][j+1];
                    int slide = t[i+1][j+1];

                    t[i][j] = max({t[i][j],grow,take,slide});
                }
                  int grow = t[i][j+1];
                  int slide = t[i+1][j+1];
               
               t[i][j] = max({t[i][j] , grow,slide});

            }
         }

 

       return t[0][k-1];
    }
};