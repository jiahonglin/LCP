class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        vector<int> nums;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                nums.push_back(matrix[i][j]);
            }
        }
        sort(nums.begin(), nums.end());
        return nums[k-1];
    }
};
