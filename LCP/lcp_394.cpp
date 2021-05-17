class Solution {
public:
    string decodeString(string s) {
        stack<int> snum;
        stack<string> sstr;
        string t="";
        int cnt=0;
        for(int i=0; i<s.size();i++){
            if(s[i] >=0 && s[i] <= '9'){
                cnt=cnt*10+s[i]-'0';
            }
            else if(s[i] == '['){
                snum.push(cnt);
                sstr.push(t);
                cnt=0;
                t="";
            }
            else if(s[i] == ']'){
                int repeat=snum.top();
                string tmp=sstr.top();
                snum.pop();
                sstr.pop();
                while(repeat > 0){
                    repeat--;
                    tmp+=t;
                }
                t=tmp;
            }
            else{
                t+=s[i];
            }
        }
        return t;
    }

    /*
    string decodeString(string s) {
        int i = 0;
        return decode(s,i);
    }
    
    string decode(string s, int& i){
        string res="";
        while(i<s.size() && s[i] != ']'){
            if(s[i] < '0' || s[i] > '9'){
                res+=s[i++];
            }
            else{
                int cnt = 0;
                while(s[i] >= '0' && s[i] <= '9'){
                    cnt = cnt*10 + s[i++]-'0';
                }
                i++;
                string t = decode(s,i);
                for(int j=0;j<cnt;j++) res+=t;
                i++;
            }
        }
        return res;
    }
    */
};
