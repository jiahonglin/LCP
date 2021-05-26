class Solution {
public:
    void reverseString(vector<char>& s) {
        doReverse(s,0);
    }
    void doReverse(vector<char>& s, int offset){
        if((s.size()-1-offset) <= offset) return;
        else{
            char tmp = s[offset];
            s[offset] = s[s.size()-1-offset];
            s[s.size()-1-offset] = tmp;
            doReverse(s,offset+1);
        }
    }
};
