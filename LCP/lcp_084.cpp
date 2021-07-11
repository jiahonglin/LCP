class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res=0;
        stack<int> st;
        heights.push_back(0);
        for(int i=0;i<heights.size();i++){
            if(st.empty()||heights[st.top()] < heights[i]){
                st.push(i);
            }
            else{
                int cur = st.top(); st.pop();
                res = max(res,heights[cur]*( st.empty()?i:(i-st.top()-1) ));
                i--;
            }
        }
        return res;
    }
};
