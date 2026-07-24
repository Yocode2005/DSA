class Solution {
public:
    string minWindow(string s, string t) {

        // Stores the frequency of every character required from string t
        vector<int> need(128, 0);

        // Count frequency of each character in t
        for (char c : t)
            need[c]++;

        // Sliding window pointers
        int left = 0;
        int right = 0;

        // Number of characters still needed to make the window valid
        int required = t.size();

        // Stores the starting index and minimum length of the answer
        int start = 0;
        int minLen = INT_MAX;

        // Expand the window by moving right pointer
        while (right < s.size()) {

            // If current character is still needed,
            // then we've satisfied one required character.
            if (need[s[right]] > 0)
                required--;

            // Decrease its count.
            // It can become negative if extra copies exist.
            need[s[right]]--;

            // Move right pointer forward
            right++;

            // If required becomes 0,
            // current window contains all characters of t
            while (required == 0) {

                // Update minimum window if current one is smaller
                if (right - left < minLen) {
                    minLen = right - left;
                    start = left;
                }

                // Remove leftmost character from window
                need[s[left]]++;

                // If its count becomes positive,
                // it means this character is now missing,
                // so window becomes invalid.
                if (need[s[left]] > 0)
                    required++;

                // Shrink window
                left++;
            }
        }

        // If no valid window found return ""
        if (minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};