class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1,
                       vector<vector<int>>& img2) {

        int n = img1.size();

        vector<pair<int,int>> A;
        vector<pair<int,int>> B;

        // Store coordinates of 1s in img1
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {

                if(img1[i][j] == 1) {
                    A.push_back({i, j});
                }

                if(img2[i][j] == 1) {
                    B.push_back({i, j});
                }
            }
        }

        // Count frequency of every possible translation
        map<pair<int,int>, int> mp;

        int ans = 0;

        for(auto p1 : A) {
            for(auto p2 : B) {

                int dr = p2.first - p1.first;
                int dc = p2.second - p1.second;

                mp[{dr, dc}]++;

                ans = max(ans, mp[{dr, dc}]);
            }
        }

        return ans;
    }
};