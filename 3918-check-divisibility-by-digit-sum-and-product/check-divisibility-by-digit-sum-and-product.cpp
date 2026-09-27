class Solution {
public:
    bool checkDivisibility(int n) {
         
         int digsum =0;
         int digproduct =1;
         int m = n;

         while(n != 0){
             digsum += n%10;
             digproduct *= n%10;
              n/= 10;
         }

         int totalsum  = digsum + digproduct;

         if(m%totalsum == 0) return true;

         return false;

    }
};