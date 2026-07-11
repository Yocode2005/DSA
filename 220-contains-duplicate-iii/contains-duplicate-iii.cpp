class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {

        set<long long> st;

        for (int i = 0; i < nums.size(); i++) {

            // Search for first value >= nums[i] - valueDiff
            auto it = st.lower_bound((long long)nums[i] - valueDiff);

            // Check if it lies within [nums[i]-valueDiff, nums[i]+valueDiff]
            if (it != st.end() && *it <= (long long)nums[i] + valueDiff)
                return true;

            // Insert current value
            st.insert(nums[i]);

            // Remove the oldest value to keep only the last indexDiff elements
            if (i >= indexDiff)
                st.erase(nums[i - indexDiff]);
        }

        return false;
    }
};