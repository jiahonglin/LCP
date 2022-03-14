class Solution {
public:
    int calculate(string s) {
        string tmp="";
        for(auto c:s){
            if(c != ' ') tmp+=c;
        }
        s=tmp;
        int num=0;
        stack<int> st;
        char op='+';
        int i = 0;
        int res=0;
        while(i<s.length()){
            while(isdigit(s[i]) && i<s.length()){
                num=num*10+(s[i++]-'0');
            }
            if(op == '+' ){
                st.push(num);
            }
            else if(op == '-'){
                st.push(-num);
            }
            else if(op == '*'){
                st.top()=st.top()*num;
            }
            else{
                st.top()=st.top()/num;
            }
            if(s[i] != ' ') op=s[i++];
            num=0;
        }
        while(!st.empty()){
            res+=st.top();
            st.pop();
        } 
        return res;
    }
};
