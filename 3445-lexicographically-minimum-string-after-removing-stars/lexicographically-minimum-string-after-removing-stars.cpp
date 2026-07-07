#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    struct Compare {
        bool operator()(const pair<char, int>& a, const pair<char, int>& b) {
            if (a.first != b.first) {
                return a.first > b.first; 
            }
            return a.second < b.second;
        }
    };

    string clearStars(string s) {
        int n = s.length();
        priority_queue<pair<char, int>, vector<pair<char, int>>, Compare> pq;
        vector<bool> deleted(n, false);

        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                if (!pq.empty()) {
                    auto topElement = pq.top();
                    pq.pop();
                    deleted[topElement.second] = true;
                }
            } else {
                pq.push({s[i], i});
            }
        }

        string result = "";
        for (int i = 0; i < n; i++) {
            if (s[i] != '*' && !deleted[i]) {
                result += s[i];
            }
        }

        return result;
    }
};