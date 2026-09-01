class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int startR = 0, startC = 0;

        // Give every litter cell an index
        vector<vector<int>> id(m, vector<int>(n, -1));

        int litterCount = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    startR = i;
                    startC = j;
                }

                if (classroom[i][j] == 'L') {
                    id[i][j] = litterCount++;
                }
            }
        }

        // No litter
        if (litterCount == 0) {
            return 0;
        }

        int totalMasks = 1 << litterCount;

        // visited[row][col][energy][mask]
        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(totalMasks, false)
                )
            )
        );

        // row, col, remaining energy, mask
        queue<tuple<int, int, int, int>> q;

        q.push({startR, startC, energy, 0});

        visited[startR][startC][energy][0] = true;

        int moves = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                auto [r, c, currEnergy, mask] = q.front();
                q.pop();

                // All litter collected
                if (mask == totalMasks - 1) {
                    return moves;
                }

                // Cannot move if energy is 0
                if (currEnergy == 0) {
                    continue;
                }

                for (int d = 0; d < 4; d++) {

                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    // Outside grid
                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n) {
                        continue;
                    }

                    // Obstacle
                    if (classroom[nr][nc] == 'X') {
                        continue;
                    }

                    // Moving costs 1 energy
                    int newEnergy = currEnergy - 1;

                    // R resets energy
                    if (classroom[nr][nc] == 'R') {
                        newEnergy = energy;
                    }

                    int newMask = mask;

                    // If this is a litter cell
                    if (classroom[nr][nc] == 'L') {

                        int litterIndex = id[nr][nc];

                        newMask |= (1 << litterIndex);
                    }

                    // Already visited this exact state
                    if (visited[nr][nc][newEnergy][newMask]) {
                        continue;
                    }

                    visited[nr][nc][newEnergy][newMask] = true;

                    q.push({
                        nr,
                        nc,
                        newEnergy,
                        newMask
                    });
                }
            }

            moves++;
        }

        return -1;
    }
};