class Solution {
public:
    bool uniformArray(vector<int>& nums) {

    int n = nums.size();

    vector<int>odd ;


    for(int i=0;i<n;i++){
        if(nums[i]%2 != 0) odd.push_back(nums[i]);
        
    }
    

     sort(odd.begin(),odd.end());

   // odd bnane ka try

   bool poss = true;

   for(int i=0;i<n;i++){
     if(nums[i]%2 != 1){
       int ind = upper_bound(odd.begin(),odd.end(),nums[i])-odd.begin();
       if(ind == 0){
        poss = false;
         break;
         }
         else {
            if(ind == 1){
                
            }
         }
     }
   }

   if(poss){
    return true;
   }
   else poss = true;

   //even bnane ka try;

  for(int i=0;i<n;i++){
     if(nums[i]%2 == 1){
       auto ind = upper_bound(odd.begin(),odd.end(),nums[i]);
       int indi = ind-odd.begin();
       if(indi == 0){
        poss = false;
         break;
         }
         else if(indi  == 1 && nums[i] == odd[0]){
            poss = false;
         break;
         }
     }
   }
   

   if(poss) return true;

   else return false;

        
    }
};