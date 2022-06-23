class Solution {
public:
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
};
