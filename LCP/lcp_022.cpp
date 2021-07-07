class Solution {
public:
    /*Method 2*/
    vector<string> generateParenthesis(int n) {
        unordered_set<string> st;
        if(n==0) st.insert("");
        else{
            vector<string> base = generateParenthesis(n-1);
            for(auto a:base){
                for(int i=0;i<a.size();i++){
                    if(a[i] == '('){
                        a.insert(a.begin()+i+1,'(');
                        a.insert(a.begin()+i+2,')');
                        st.insert(a);
                        a.erase(a.begin()+i+1,a.begin()+i+3);
                    }
                }
                st.insert("()" + a);
            }
        }
        return vector<string>(st.begin(),st.end());
    }
    /*Method 1*/
    /*
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string out="";
        generateParenthesis(n,n,out,res);
        return res;
    }
    void generateParenthesis(int left, int right, string out, vector<string>& res){
        if(left > right) return;
        if(left==0 && right==0) res.push_back(out);
        else{
            if(left > 0) generateParenthesis(left-1, right, out+"(", res);
            if(right > 0) generateParenthesis(left, right-1, out+")", res);
        }
    }
    */
};
