class Solution {
public:
    bool isPerfectSquare(int num) {
        int left, right, mid, sqrt;
        left = 1;
        right = num;
        if(num == 1) return true;
        while(left < right)
        {
            mid = left + (right - left)/2;
            if(num/mid < mid) 
                right = mid;
            else
                left = mid+1;         

        }
        sqrt = left - 1;
        if(num == sqrt*sqrt)
            return true;
        else
            return false;
    }
};
