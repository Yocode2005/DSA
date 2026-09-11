class Solution {
public:
    // Function to find the maximum number of fruits we can collect with at most two fruit types
    int totalFruit(vector<int>& fruits) {
        // Hash map to store frequency of each fruit in the current window
        unordered_map<int, int> basket;
        
        // Variable to store the maximum length of valid window
        int maxFruits = 0;
        
        // Left pointer of the sliding window
        int left = 0;

        // Traverse the fruits array using right pointer
        for (int right = 0; right < fruits.size(); right++) {
            // Include the current fruit in the basket
            basket[fruits[right]]++;

            // Shrink the window if more than 2 types of fruits exist
            while (basket.size() > 2) {
                // Decrease count of fruit at left pointer
                basket[fruits[left]]--;

                // If count becomes zero, remove it from map
                if (basket[fruits[left]] == 0) {
                    basket.erase(fruits[left]);
                }

                // Move the left pointer to shrink the window
                left++;
            }

            // Update the maximum window length found so far
            maxFruits = max(maxFruits, right - left + 1);
        }

        // Return the maximum fruits we can collect in a valid window
        return maxFruits;
    }
};