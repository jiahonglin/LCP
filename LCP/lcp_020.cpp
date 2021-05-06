class Solution {
public:
    bool isValid(string s) {
        int strlen = s.length();
        int i=0;
        stack<char> charstack;
        while(i <= strlen){
            if(s[i] == '[' || s[i] == '{' || s[i] == '('){
                charstack.push(s[i]);
            }
            else if(s[i] == ']'){
                if(charstack.empty() || charstack.top() != '[') return false;
                charstack.pop();
            }
            else if(s[i] == '}'){
                if(charstack.empty() || charstack.top() != '{') return false;
                charstack.pop();
            }
            else if(s[i] == ')'){
                if(charstack.empty() || charstack.top() != '(') return false;
                charstack.pop();
            }
            i++;
        }
        if(charstack.empty()) return true;
        else return false;
    }
};
