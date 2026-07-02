class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char,int> mp;

        int left =0;
        int right =0;
        int n = s.length();

        int ans =0;

        while(right < n ){

            if(mp.find(s[right]) == mp.end() || mp[s[right]] < left){
              ans = max(ans,right-left+1);
              mp[s[right]] = right;
              right++;
            }

            else{
                left = mp[s[right]]+1; 
                mp[s[right]] = right;
                ans = max(right-left+1,ans);
                right++; 
            }
        }

        return ans;
    }
};