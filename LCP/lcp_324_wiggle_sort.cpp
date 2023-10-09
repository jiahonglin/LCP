class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> element = nums;
        sort(element.begin(),element.end());
        int n = nums.size();
        int mid = (n+1)/2;
        int tail = n;
        for(int i = 0;i<n;i++){
            nums[i] = i&1?element[--tail]:element[--mid];
        }
    }
};
