class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> uglyNum(1,1);
        int u2=0,u3=0,u5=0;
        while(uglyNum.size() < n){
            int c2 = uglyNum[u2]*2;
            int c3 = uglyNum[u3]*3;
            int c5 = uglyNum[u5]*5;
            int minimum = min(c2, min(c3,c5));
            if(minimum == c2) u2++;
            if(minimum == c3) u3++;
            if(minimum == c5) u5++;
            uglyNum.push_back(minimum);
        }
        return uglyNum.back();
    }
};
