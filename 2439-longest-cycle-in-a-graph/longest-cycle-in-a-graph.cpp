#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> visited(n, false);
        int maxCycle = -1;

        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;

            // Tracks {node -> step_number} for the CURRENT path traversal only
            unordered_map<int, int> nodeDistance;
            int curr = i;
            int step = 1;

            while (curr != -1) {
                // If node is not globally visited, mark and continue path
                if (!visited[curr]) {
                    visited[curr] = true;
                    nodeDistance[curr] = step++;
                    curr = edges[curr];
                } 
                // If node was visited in THIS CURRENT traversal path -> Cycle found!
                else if (nodeDistance.count(curr)) {
                    int cycleLen = step - nodeDistance[curr];
                    maxCycle = max(maxCycle, cycleLen);
                    break;
                } 
                // If node was visited in a PREVIOUS traversal path -> Stop
                else {
                    break;
                }
            }
        }

        return maxCycle;
    }
};