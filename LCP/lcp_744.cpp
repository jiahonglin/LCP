class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {

        int left, right, mid;
        left = 0;
        right = letters.size()-1;
        while(right > left)
        {
            mid = left + (right - left)/2;
            
            if(int(letters[mid]) > int(target))
            {
                right = mid;
            }
            else
            {
                left = mid+1;
            }
        }
        if(letters[left] == target)
        {
            if(left+1 == letters.size())
            {
                return letters[0];
            }
            else
            {
                return letters[left+1];
            }
        }
        else
        {
            if(int(letters[left]) < int(target))
                return letters[0];
            else
                return letters[left];
        }

        /*
        if(target >= letters.back()) return letters[0];
        int left, right, mid;
        left = 0;
        right = letters.size()-1;
        while(right > left)
        {
            mid = left + (right - left)/2;
            if(letters[mid] > target)
            {
                right = mid;
            }
            else
            {
                left = mid+1;
            }
        }
        return letters[left];
        */
    }
};
