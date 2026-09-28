#include <algorithm>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();
        int currentOpen = 0;
        int maxOpen = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                currentOpen++;
                maxOpen = max(maxOpen, currentOpen);
            }
            else if(s[i] == ')') {
                currentOpen--;
            }
        }
        return maxOpen;
    }
};
