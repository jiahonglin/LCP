class Solution {
public:
    int myAtoi(string s) {

        int size = s.length();
        int startIdx = 0;
        int sign = 1;
        long long int num=0;
        while(startIdx < size && s[startIdx] == ' ') startIdx++;
        if(s[startIdx] == '-'){
            sign = -1;
            startIdx++;
        }
        else if(s[startIdx] == '+'){
            startIdx++;
        }
        if(!isdigit(s[startIdx])) return 0;

        for(int i=startIdx; i<size;i++){
            if(isdigit(s[i])){
                num = num*10 + s[i]-'0';
            }
            else{
                return sign * num;
            }
            if(INT_MAX < num && sign==1) return INT_MAX;
            if(INT_MAX < num && sign==-1) return INT_MIN;
        }
        return num*sign;

    }
};
