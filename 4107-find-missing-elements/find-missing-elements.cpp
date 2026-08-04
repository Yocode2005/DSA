class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int>list;
        int j = 0;
        for(int i = nums[0];i<nums[n-1];i++){
            if(nums[j] == i){
                j++;
            }
            else{
                list.push_back(i);
            }
        }
        return list;
    }
};