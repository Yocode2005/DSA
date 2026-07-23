class Solution {
public:
    int jump(vector<int>& nums) {
    //  int jump = 0,l = 0,r = 0;
    //  int n = nums.size();
    //  while(r<n-1){
    //     int longest = 0;
    //     for(int i = l;i<=r;i++){
    //         longest = max(longest,i + nums[i]);
    //     }
    //     l = r+1;
    //     r = longest;
    //     jump = jump+1;
    //  }
    //  return jump;
      int jumps = 0, currentEnd = 0, farthest = 0;

        // Traverse through the array (excluding the last element)
        for (int i = 0; i < nums.size() - 1; ++i) {
            // Update the farthest index that can be reached so far
            farthest = max(farthest, i + nums[i]);

            // When we reach the end of the current jump range
            if (i == currentEnd) {
                // We need to make a jump
                jumps++;

                // Move the current end to the farthest index we can reach
                currentEnd = farthest;
            }
        }

        // Return the total jumps needed
        return jumps;
    }
};