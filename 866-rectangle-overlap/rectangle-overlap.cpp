class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        
        int x1 = rec1[0];
        int y1 = rec1[1];
        int x2 = rec1[2];
        int y2 = rec1[3];

        int x3 = rec2[0];
        int y3 = rec2[1];
        int x4 = rec2[2];
        int y4 = rec2[3];

        // Check overlap on X-axis
        bool xOverlap = (x1 < x4 && x3 < x2);

        // Check overlap on Y-axis
        bool yOverlap = (y1 < y4 && y3 < y2);

        return xOverlap && yOverlap;
    }
};