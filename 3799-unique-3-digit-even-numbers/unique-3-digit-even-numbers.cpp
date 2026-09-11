class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        
        vector freq(10, 0);
        for (int x : digits) {
            freq[x]++;
        }

        int ans = 0;
        for (int i = 100; i <= 998; i += 2) {
            int a = i / 100;
            int b = (i / 10) % 10;
            int c = i % 10;

            vector req(10, 0);
            req[a]++;
            req[b]++;
            req[c]++;

            bool ok = true;
            for (int d = 0; d < 10; d++) {
                if (req[d] > freq[d]) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                ans++;
            }
        }

        return ans;
    }
};