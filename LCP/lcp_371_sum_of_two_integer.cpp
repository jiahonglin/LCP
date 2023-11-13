class Solution {
public:
    int getSum(int a, int b) {
        int ans=0;
        int carry=0;
        for(int i=0;i<32;i++){
            int a_bit = a & (1<<i)?1:0;
            int b_bit = b & (1<<i)?1:0;
            ans |= ((a_bit ^ b_bit ^ carry) << i);
            int onecnt=0;
            if(a_bit == 1) onecnt++;
            if(b_bit == 1) onecnt++;
            if(carry == 1) onecnt++;
            if(onecnt >= 2) carry=1;
            else carry=0;
        }
        return ans;
    }
};
