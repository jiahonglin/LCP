class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        /*
        for (int i = 0; i < numbers.size(); i++) {
            int t = target - numbers[i];
            int left = i + 1;
            int right = numbers.size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (numbers[mid] == t) return {i + 1, mid + 1};
                else if (numbers[mid] < t) left = mid + 1;
                else right = mid;
            }
        }
        return {};
        */

        int i=0;
        int j=numbers.size()-1;
        while(i<j){
            if(numbers[i]+numbers[j] == target)
                return {i+1,j+1};
            else if(numbers[i]+numbers[j] > target)
                j--;
            else
                i++;
                
        }
        return {};

    }

};
