#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> orig_freq(26, 0);
        for (char c : s) {
            orig_freq[c - 'a']++;
        }

        int best_split = -1;
        int best_char = -1;

        vector<int> freq = orig_freq;

        for (int i = 0; i < n; i++) {
            int t_char = target[i] - 'a';

            for (int c = t_char + 1; c < 26; c++) {
                if (freq[c] > 0) {
                    best_split = i;
                    best_char = c;
                    break;
                }
            }

            if (freq[t_char] > 0) {
                freq[t_char]--;
            } else {
                break;
            }
        }

        if (best_split == -1) return "";

        string result = "";
        freq = orig_freq;

        for (int i = 0; i < best_split; i++) {
            result += target[i];
            freq[target[i] - 'a']--;
        }

        result += (char)('a' + best_char);
        freq[best_char]--;

        for (int c = 0; c < 26; c++) {
            while (freq[c] > 0) {
                result += (char)('a' + c);
                freq[c]--;
            }
        }

        return result;
    }
};