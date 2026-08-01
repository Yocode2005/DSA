class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[1] > b[1];
             });

        int totalUnit = 0;

        for (auto &it : boxTypes) {
            if (truckSize == 0) break;

            int boxes = min(it[0], truckSize);
            totalUnit += boxes * it[1];
            truckSize -= boxes;
        }

        return totalUnit;
    }
};