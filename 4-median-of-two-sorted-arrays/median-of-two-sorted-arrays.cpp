class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int>temp(m+n);
        int i = 0; // nums1
        int j = 0;// nums2
        int k = 0;// temp
        while(i<n && j<m){
            if(nums1[i]<nums2[j]){
                temp[k] = nums1[i];
                i++;
                k++;
            }
            else{
                temp[k] = nums2[j];
                j++;
                k++;
            }
        }
        while(i<n){ // if elements left in nums1 after completion of  nums2
            temp[k] = nums1[i];
            i++;
            k++;
        }
        while(j<m){ // if elements left in nums2 after completion of  nums1
            temp[k] = nums2[j];
            j++;
            k++;
        }
        int size = m+n;
        if(size%2 == 1){ // odd
            return temp[size/2];
        }
        else return (temp[size/2] + temp[(size/2)-1])/2.0; // even
    }
};