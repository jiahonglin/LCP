class Solution {
public:
    int addDigits(int num) {
        int remain = 0;
        if(num < 10) return num;
        while(num > 0){
            int r = num%10;
            num = (num-r)/10;
            remain+=r;
        }
        return addDigits(remain);
    }
};
