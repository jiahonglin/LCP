class Solution {
public:
    bool queryString(string s, int n) {
        for(int i=1;i<=n;i++){
            string binary = toString(i);
            if(s.find(binary) == string::npos) return false;
        }
        return true;
    }
    string toString(int n){
        string bin;
        while(n>0){
            int r = n%2;
            if(r==1) bin+='1';
            else bin+='0';
            n/=2;
        }
        reverse(bin.begin(),bin.end());
        return bin;
    }
};
