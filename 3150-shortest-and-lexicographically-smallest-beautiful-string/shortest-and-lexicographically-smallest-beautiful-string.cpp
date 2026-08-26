class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
         
         int n = s.length();
         int count =0;
         for(int i=0;i<n;i++){
            if(s[i] == '1') count++;
         }

         if(count <k) return "";
         int left =0;
         int right =0;
         count =0;
         string res= "";
         int minl =  INT_MAX;

         while(right <n){
            
            if(s[right] == '1') count++;
            
             if(count  == k){
                while(s[left] == '0') left++;

                 if(minl > right-left+1){
                    res =  s.substr(left,right-left+1);
                    minl = right-left+1;
                       
                 }   
 
                if(minl == right-left+1){

                if(res == "") res = s.substr(left,right-left+1);
                else if( res >  s.substr(left,right-left+1)) res =  s.substr(left,right-left+1);

               
                }
                left++;
                count--;

             }

             right++;

         }

         return res;  
           
    } 
};