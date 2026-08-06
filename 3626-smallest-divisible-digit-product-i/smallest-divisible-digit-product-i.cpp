class Solution {

    int mult(int n){
        int prod =1;

        while(n!=0){
            prod *= n%10;
            n = n/10;
        }
        return prod;
    }
public:
    int smallestNumber(int n, int t) {
        
        if(mult(n)%t == 0) return n;


        while(true){

            if(mult(n)%t == 0) return n;

            n++;
        }

    }
};