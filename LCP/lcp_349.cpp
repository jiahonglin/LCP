class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> intersect;
        bool repeat = false;
        for(int i=0; i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                if(nums1[i] == nums2[j])
                {
                    repeat = false;
                    for(int k=0;k<intersect.size();k++)
                    {
                        if(nums1[i] == intersect[k])
                        {
                            repeat = true;
                        }
                    }
                    if(repeat == false)
                    {
                        intersect.push_back(nums1[i]);
                    }
                }
                
            }
        }
        return intersect;
    }
};
