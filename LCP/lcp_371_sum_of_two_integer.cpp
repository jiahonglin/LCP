class Solution {
public:
    int getSum(int a, int b) {
        int ans=0;
        int carry=0;
        for(int i=0;i<32;i++){
            int a_bit = a & (1<<i)?1:0;
            int b_bit = b & (1<<i)?1:0;
            ans |= (a_bit ^ b_bit ^ carry) << i;
            if(a_bit == 0 && b_bit == 0 && carry == 0||
              a_bit == 0 && b_bit == 1 && carry == 0 ||
               a_bit == 1 && b_bit == 0 && carry == 0 ||
               a_bit == 0 && b_bit == 0 && carry == 1
              ){
                carry=0;
            }
            else{
                carry=1;
            }
        }
        return ans;
    }
};
