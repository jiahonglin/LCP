class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int tempsize = temperatures.size();
        vector<int> sol(tempsize,0);
        stack<int> st;
        for(int i=0;i<tempsize;i++){
            while(!st.empty() && temperatures[i] > temperatures[st.top()]){
                int pos = st.top();
                st.pop();
                sol[pos] = i-pos;
            }
            st.push(i);
        }
        return sol;
    }
};
