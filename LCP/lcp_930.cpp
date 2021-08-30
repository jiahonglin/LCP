class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans = 0;
        deque<int> dq;

        for(int i = 0, j = 0; i < nums.size(); i++) {
            if(nums[i] == 1) dq.push_back(i);
            if(dq.size() > goal) j = dq.front() + 1, dq.pop_front();
            if(dq.size() == goal) {
			    if(dq.empty()) ans += (i-j+1); //Edge case, simply evaluate the current window
                else ans += (dq.front()-j+1);
            }
        }
        return ans;
        /*
        int curSum=0;
        int res=0;
        unordered_map<int,int> m{{0,1}};
        for(int i=0;i<nums.size();i++){
            curSum+=nums[i];
            res+=m[curSum-goal];
            m[curSum]++;
        }
        return res;
        */
        
    }

};
