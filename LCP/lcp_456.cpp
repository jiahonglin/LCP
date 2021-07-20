class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        int top = INT_MIN;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]<top){
                return true;
            }
            while(st.empty()==false && nums[i]>st.top()){
                top = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};
