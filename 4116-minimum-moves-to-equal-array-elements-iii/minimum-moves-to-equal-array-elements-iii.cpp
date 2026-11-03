class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int maxElement = *max_element(nums.begin(), nums.end());
        int moves = 0;
        for(int i = 0;i<n;i++){
             int diff = maxElement-nums[i];
             moves+= diff;
        }
        return moves;
    }
};