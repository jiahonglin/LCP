// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(isBadVersion(1) == true) return 1;
        int left = 1;
        int right = n;
        int mid;
        while(left < right)
        {
            mid = left + (right-left)/2;
            if(isBadVersion(mid) == true)
            {
                if(isBadVersion(mid-1) == false)
                {
                    return mid;
                }
                else
                {
                    right = mid;
                }
            }
            else
            {
                left = mid+1;
            }
        }
        return left;
    }
};
