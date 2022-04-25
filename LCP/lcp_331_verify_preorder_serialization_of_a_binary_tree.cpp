class Solution {
public:
    bool isValidSerialization(string preorder) {
        int size = preorder.length();
        int cnt = 0;
        string s="";
        vector<string> vs;
        for(int i=0;i<size-1;i++){
            if(preorder[i] == ','){
                vs.push_back(s);
                s="";
            }
            else{
                s+=preorder[i];
            }
        }
        for(int i=0;i<vs.size();i++){
            if(cnt==0 && vs[i]=="#") return false;
            else if(vs[i] == "#") cnt--;
            else cnt++;
        }
        if(cnt == 0 && preorder[size-1] == '#') return true;
        else return false;
    }
};
