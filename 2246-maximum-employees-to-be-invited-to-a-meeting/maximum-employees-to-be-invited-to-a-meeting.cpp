class Solution {
public:
    int maximumInvitations(vector<int>& favourite) {
        
        int n = favourite.size();
        vector<int> in_degree(n,0);

        for(int i=0;i<n;i++){
            in_degree[favourite[i]]++;
        }

        queue<int>q;

        for(int i=0;i<n;i++){
            if(in_degree[i]== 0){
                q.push(i);
            }
        }

        vector<int> chain_len(n,0);

        while(!q.empty()){
            int u = q.front();
            q.pop();

            int v = favourite[u];
            chain_len[v] = max(chain_len[v],chain_len[u]+1);

            in_degree[v]--;
            if(in_degree[v] ==0 ){
                q.push(v);
            }
        }
        int max_large_cycle =0;
        int sum_two_cycles =0;

        for(int i=0;i<n;i++){
            if(in_degree[i] > 0){
                int cycle_len =0;
                int curr =i;

                while(in_degree[curr]>0){
                    in_degree[curr] =0;
                    cycle_len++;
                    curr = favourite[curr];
                }

                if(cycle_len == 2){
                    int nodeA =i;
                    int nodeB = favourite[i];
                    sum_two_cycles += (2+ chain_len[nodeA] + chain_len[nodeB]);
                }

                else{
                     max_large_cycle = max(max_large_cycle,cycle_len);
                }
            }
        }

        return max(max_large_cycle,sum_two_cycles);
    }
};