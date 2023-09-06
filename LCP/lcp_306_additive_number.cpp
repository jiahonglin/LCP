class Solution {
public:
    bool isAdditiveNumber(string num) {
        for(int i=1;i<num.length();i++){
            string s1 = num.substr(0,i);
            if(s1.length()>1 && s1[0]=='0') break;
            for(int j=i+1;j<num.length();j++){
                string s2 = num.substr(i,j-i);
                if(s2.length()>1 && s2[0]=='0') continue;
                long d1 = stol(s1);
                long d2 = stol(s2);
                long next = d1+d2;
                string nextstr = to_string(next);
                string allstr = s1+s2+nextstr;
                while(allstr.length()<num.length()){
                    d1 = d2;
                    d2 = next;
                    next = d1+d2;
                    nextstr = to_string(next);
                    allstr+=nextstr;
                }
                if(allstr == num) return true;
            }
        }
        return false;
    }
/*
    bool isAdditiveNumber(string num) {
        for(int i = 1; i<= num.size()/2; i++){
            for(int j = 1; j<= (num.size()-i)/2 ;j++){
                if( check(num.substr(0,i), num.substr(i,j), num.substr(i+j)) ) return true;
            }
        }
        return false;
    }
    bool check(string num1, string num2, string rest){
        if((num1.size() > 1 && num1[0] == '0') || (num2.size() > 1 && num2[0] == '0') ) return false;
        string sum = add(num1,num2);
        if(sum == rest) return true;
        if(sum.size() >= rest.size() || sum.compare(rest.substr(0,sum.size()))!=0) return false;
        else return check(num2, sum, rest.substr(sum.size()));
    }
    string add(string a, string b){
        string res;
        int i = a.size()-1;
        int j = b.size()-1;
        int carry = 0;
        while(i >=0 || j >= 0){
            int sum = carry + (i>=0?(a[i--]-'0'):0) + (j >=0 ? (b[j--]-'0'):0);
            res.push_back(sum%10+'0');
            carry=sum/10;
        }
        if(carry) res.push_back(carry+'0');
        reverse(res.begin(), res.end());
        return res;
    }
    */
};
