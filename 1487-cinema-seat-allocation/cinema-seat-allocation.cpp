class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        // Store the reserved seats for only those rows
        // that actually have reservations.
        unordered_map<int, int> mp;

        // Mark each reserved seat using a bit.
        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            mp[row] |= (1 << col);
        }

        // Initially, every row can accommodate 2 families.
        int ans = 2 * n;

        // We only need to check rows having reservations.
        for (auto &[row, mask] : mp) {

            // Left group: seats 2,3,4,5
            bool left = !(mask & (1 << 2)) &&
                        !(mask & (1 << 3)) &&
                        !(mask & (1 << 4)) &&
                        !(mask & (1 << 5));

            // Right group: seats 6,7,8,9
            bool right = !(mask & (1 << 6)) &&
                         !(mask & (1 << 7)) &&
                         !(mask & (1 << 8)) &&
                         !(mask & (1 << 9));

            // Middle group: seats 4,5,6,7
            bool middle = !(mask & (1 << 4)) &&
                          !(mask & (1 << 5)) &&
                          !(mask & (1 << 6)) &&
                          !(mask & (1 << 7));

            // This row was initially counted as 2.
            if (left && right) {
                // Still can accommodate 2 families.
            }
            else if (left || middle || right) {
                // Can accommodate only 1 family.
                ans--;
            }
            else {
                // Cannot accommodate any family.
                ans -= 2;
            }
        }

        return ans;
    }
};