class Solution {
public:
    string reorganizeString(string s) {

        unordered_map<char,int> mp;
        int n= s.length();

        for(int i=0;i<n;i++){
             mp[s[i]]++;

             if(mp[s[i]] > (n+1)/2){
                return "";
             }
        }

        priority_queue<pair<int,char>> pq;

        for(auto &[ch,freq] : mp){
             pq.push({freq,ch});
        }

     string result ="";
        while(pq.size()>= 2){

             auto temp1 = pq.top();
             pq.pop();
             auto temp2 = pq.top();
             pq.pop();

             result += temp1.second;
            if(temp1.first >1)  pq.push({temp1.first-1,temp1.second});

            result += temp2.second;
            if(temp2.first >1)  pq.push({temp2.first-1,temp2.second});
           
        }
  
        if(!pq.empty()){
            result += pq.top().second;
        }

        return result;

    }
};