class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        
      int c0 = 0, c1 = 0, c2 = 0;
        
        // Count stones based on their remainder when divided by 3
        for (int stone : stones) {
            if (stone % 3 == 0) c0++;
            else if (stone % 3 == 1) c1++;
            else c2++;
        }
        
        // If the count of multiples of 3 is even
        if (c0 % 2 == 0) {
            return c1 > 0 && c2 > 0;
        } 
        // If the count of multiples of 3 is odd
        else {
            return abs(c1 - c2) > 2;
        }
    }
};