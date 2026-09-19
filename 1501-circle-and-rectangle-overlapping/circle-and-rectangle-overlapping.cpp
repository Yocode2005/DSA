class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int xMax = max(x1,min(xCenter,x2));
        int yMax = max(y1,min(yCenter,y2));
        int distX = xMax-xCenter;
        int distY = yMax-yCenter;

        if(distX*distX + distY*distY <= radius*radius){
            return true;
        }
        return false;
    }
};