#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
private:
    // Helper function using Rolling Hash (Rabin-Karp) to find pattern matches
    vector<int> getMatches(const string& s, const string& p) {
        int n = s.length();
        int m = p.length();
        vector<int> matches;
        if (n < m) return matches;

        long long base = 31;
        long long mod = 1e9 + 7;

        long long hash_p = 0;
        long long hash_s = 0;
        long long power = 1;

        // Precompute base^(m-1) % mod
        for (int i = 0; i < m - 1; i++) {
            power = (power * base) % mod;
        }

        // Compute initial hash for pattern p and first window of s
        for (int i = 0; i < m; i++) {
            hash_p = (hash_p * base + (p[i] - 'a' + 1)) % mod;
            hash_s = (hash_s * base + (s[i] - 'a' + 1)) % mod;
        }

        if (hash_p == hash_s && s.substr(0, m) == p) {
            matches.push_back(0);
        }

        // Slide the window across s
        for (int i = m; i < n; i++) {
            // Remove leftmost character and add rightmost character
            hash_s = (hash_s - ((s[i - m] - 'a' + 1) * power) % mod + mod) % mod;
            hash_s = (hash_s * base + (s[i] - 'a' + 1)) % mod;

            // If hashes match, verify substring to handle rare collisions
            if (hash_s == hash_p) {
                if (s.substr(i - m + 1, m) == p) {
                    matches.push_back(i - m + 1);
                }
            }
        }

        return matches;
    }

public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        // Step 1: Get match indices using Rolling Hash in O(|s|) time
        vector<int> indices_a = getMatches(s, a);
        vector<int> indices_b = getMatches(s, b);
        vector<int> result;

        if (indices_a.empty() || indices_b.empty()) return result;

        // Step 2: Binary Search in indices_b for each index i in indices_a
        for (int i : indices_a) {
            auto it = lower_bound(indices_b.begin(), indices_b.end(), i - k);
            if (it != indices_b.end() && *it <= i + k) {
                result.push_back(i);
            }
        }

        return result;
    }
};