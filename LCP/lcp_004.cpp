class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        /*
        vector<int> merged;
        double sol=0;
        for(int i=0;i<nums1.size();i++) merged.push_back(nums1[i]);
        for(int j=0;j<nums2.size();j++) merged.push_back(nums2[j]);
        sort(merged.begin(),merged.end());
        if(merged.size()%2 == 0){
            sol = (double)(merged[merged.size()/2] + merged[merged.size()/2-1])/2;
        }
        else{
            sol = (double)merged[(merged.size())/2];
        }
        return sol;
        */
        int m = nums1.size(), n = nums2.size();
        int left = (m+n+1)/2, right = (m+n+2)/2;
        return (findKth(nums1,0,nums2,0,left)+findKth(nums1,0,nums2,0,right))/2.0;
    }
    int findKth(vector<int>& nums1, int i, vector<int>&nums2, int j, int k){
        if(i>=nums1.size()) return nums2[j+k-1];
        if(j>=nums2.size()) return nums1[i+k-1];
        if(k==1) return min(nums1[i],nums2[j]);
        int midVal1 = ((i+k/2-1)<nums1.size())?nums1[i+k/2-1]:INT_MAX;
        int midVal2 = ((j+k/2-1)<nums2.size())?nums2[j+k/2-1]:INT_MAX;
        if(midVal1 < midVal2){
            return findKth(nums1,i+k/2,nums2,j,k-k/2);
        }
        else{
            return findKth(nums1,i,nums2,j+k/2,k-k/2);
        }
    }
};
