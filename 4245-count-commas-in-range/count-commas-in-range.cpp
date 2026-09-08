class Solution {

    int find_len(int n){
         int length =0;
       while(n!=0){
          length++;
          n= n/10;
       }
       if(length%3 ==0){
        return length/3-1;
       }

       else return length/3;
    }
public:
    int countCommas(int n) {
      
      
       if(n<1000) return 0;

        int ans =0;

        for(int i=1000;i<=n;i++){
            ans += find_len(i);
        }

        return ans;
    }
};