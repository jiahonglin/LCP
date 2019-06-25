// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        if(guess(n) == 0) return n;
        int start = 1;
        int end = n;
        int ret;
        int mid;
        while(end > start)
        {
            mid = start + (end-start)/2;
            ret = guess(mid);
            if(ret == 0)
                return mid;
            else if(ret == 1)
                start = mid;
            else
                end = mid;
        }
        return end;
    }
    
};
