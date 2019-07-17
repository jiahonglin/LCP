class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans = arr;
        while(ans.size() > k)
        {
            if(abs(x-ans.front()) <= abs(x-ans.back()))
                ans.pop_back();
            else
                ans.erase(ans.begin());
        }
        return ans;
    }
};

