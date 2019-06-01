class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
    	int pos = 0;
        for(int i = 0; i < nums.size(); i++)
		{
			if(target > nums[i])
			{
				pos++;
			}
		}
        return pos;
    }
};
