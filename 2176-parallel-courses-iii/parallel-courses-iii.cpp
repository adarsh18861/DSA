#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        // 1. Adjacency list and in-degree array setup (1-indexed)
        vector<vector<int>> adj(n + 1);
        vector<int> inDegree(n + 1, 0);

        for (const auto& rel : relations) {
            int prevCourse = rel[0];
            int nextCourse = rel[1];
            adj[prevCourse].push_back(nextCourse);
            inDegree[nextCourse]++;
        }

        // 2. maxTime[i] stores the total time needed to complete course i
        vector<int> maxTime(n + 1, 0);
        queue<int> q;

        // 3. Initialize courses with 0 prerequisites
        for (int i = 1; i <= n; i++) {
            maxTime[i] = time[i - 1]; // Base duration of the course
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        // 4. Topological Processing via Kahn's Algorithm
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                // Relaxation step: Update maximum time to finish course v
                maxTime[v] = max(maxTime[v], maxTime[u] + time[v - 1]);

                inDegree[v]--;
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        // 5. Find the bottleneck (maximum time among all completed courses)
        int totalMinTime = 0;
        for (int i = 1; i <= n; i++) {
            totalMinTime = max(totalMinTime, maxTime[i]);
        }

        return totalMinTime;
    }
};