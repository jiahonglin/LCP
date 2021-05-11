class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int sol = 0, i = 0;
        int strsize = tokens.size();
        while(i < strsize){
            if(tokens[i] == "+"){
                int op1 = st.top();st.pop();
                int op2 = st.top();st.pop();
                sol = op1+op2;
                st.push(sol);
            }
            else if(tokens[i] == "-"){
                int op1 = st.top();st.pop();
                int op2 = st.top();st.pop();
                sol = op2-op1;
                st.push(sol);
            }
            else if(tokens[i] == "*"){
                int op1 = st.top();st.pop();
                int op2 = st.top();st.pop();
                sol = op1*op2;
                st.push(sol);
            }
            else if(tokens[i] == "/"){
                int op1 = st.top();st.pop();
                int op2 = st.top();st.pop();
                sol = op2/op1;
                st.push(sol);
            }
            else{
                st.push(stoi(tokens[i]));
            }
            i++;
        }
        return st.top();
    }
};
