class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<bool>exist(101);
        for(auto it : nums){
            exist[it] = true;
        }
         int num = k;
            while(num<101){
                if(!exist[num]) return num;
                num += k;
            }
        return  num;
    }
};