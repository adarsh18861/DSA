#include <vector>
#include <string>
#include <queue>

using namespace std;

struct State {
    int r, c, e, mask, dist;
};

static int vis[21][21][51][1024] = {0};
static int tc = 0;

class Solution {
    int dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};

public:
    int minMoves(vector<string>& classroom, int energy) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        tc++;

        int m = classroom.size();
        int n = classroom[0].size();
        int sr = -1, sc = -1;
        int litter_count = 0;
        int litter_id[21][21];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                litter_id[i][j] = -1;
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                } else if (classroom[i][j] == 'L') {
                    litter_id[i][j] = litter_count++;
                }
            }
        }

        int target_mask = (1 << litter_count) - 1;
        int initial_mask = 0;
        if (classroom[sr][sc] == 'L') {
            initial_mask |= (1 << litter_id[sr][sc]);
        }

        queue<State> q;
        q.push({sr, sc, energy, initial_mask, 0});
        vis[sr][sc][energy][initial_mask] = tc;

        while (!q.empty()) {
            State curr = q.front();
            q.pop();

            if (curr.mask == target_mask) return curr.dist;
            if (curr.e == 0) continue;

            for (int k = 0; k < 4; k++) {
                int nr = curr.r + dir[k][0];
                int nc = curr.c + dir[k][1];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && classroom[nr][nc] != 'X') {
                    int next_e = (classroom[nr][nc] == 'R') ? energy : curr.e - 1;
                    int next_mask = curr.mask;

                    if (classroom[nr][nc] == 'L') {
                        next_mask |= (1 << litter_id[nr][nc]);
                    }

                    if (vis[nr][nc][next_e][next_mask] != tc) {
                        vis[nr][nc][next_e][next_mask] = tc;
                        q.push({nr, nc, next_e, next_mask, curr.dist + 1});
                    }
                }
            }
        }

        return -1;
    }
};