class Solution {
public:
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
};
