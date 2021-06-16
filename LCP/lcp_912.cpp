class Solution {
public:
    /*Quick Sort 1*/
    /*
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums,0,nums.size()-1);
        return nums;
    }
    void quickSort(vector<int>& nums, int lo, int hi){
        if(lo<hi){
            int p = partition(nums, lo, hi);
            quickSort(nums, lo, p-1);
            quickSort(nums, p+1, hi);
        }
    }
    int partition(vector<int>& nums, int lo, int hi){
        int pivot = nums[hi];
        int split = lo;
        for(int j=lo;j<hi;j++){
            if(nums[j]<pivot){
                int tmp = nums[split];
                nums[split] = nums[j];
                nums[j] = tmp;
                split++;
            }
        }
        int tmp = nums[split];
        nums[split] = pivot;
        nums[hi] = tmp;
        return split;
    }
    */
    /*Quick Sort 2*/
    vector<int> sortArray(vector<int>& nums) {
        /*
        function<void(int, int)> quickSort = [&](int l, int r) {
            if (l >= r) return;      
            int i = l;
            int j = r;
            int p = nums[l + rand() % (r - l + 1)];
            while (i <= j) {
                while (nums[i] < p) ++i;
                while (nums[j] > p) --j;
                if (i <= j) swap(nums[i++], nums[j--]);
            }
            quickSort(l, j);
            quickSort(i, r);
        };
        */
        quickSort(nums,0, nums.size() - 1);
        return nums;
    }
    void quickSort(vector<int>& nums, int left, int right){
        if(left>=right) return;
        int i = left;
        int j = right;
        int pivot = nums[left+rand()%(right-left+1)];
        while(i<=j){
            while(nums[i] < pivot) i++;
            while(nums[j] > pivot) j--;
            if(i<=j){
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
                i++;j--;
            }
        }
        quickSort(nums,left,j);
        quickSort(nums,i,right);
    }

    /*Merge Sort*/
    /*
    vector<int> sortArray(vector<int>& nums) {
        if(nums.size()<=1) return nums;
        int pivot = (nums.size()+1)/2;
        vector<int> leftHalf;
        vector<int> rightHalf;
        for(int i=0;i<pivot;i++) leftHalf.push_back(nums[i]);
        for(int j=pivot;j<nums.size();j++) rightHalf.push_back(nums[j]);
        vector<int> left = sortArray(leftHalf);
        vector<int> right = sortArray(rightHalf);
        return mergeSort(left,right);
    }

    vector<int> mergeSort(vector<int> left, vector<int> right){
        int leftPivot = 0, rightPivot = 0;
        vector<int> ret;
        while(leftPivot < left.size() && rightPivot < right.size()){
            if(left[leftPivot] <= right[rightPivot]){
                ret.push_back(left[leftPivot++]);
            }
            else{
                ret.push_back(right[rightPivot++]);
            }
        }
        while(leftPivot<left.size()) ret.push_back(left[leftPivot++]);
        while(rightPivot<right.size()) ret.push_back(right[rightPivot++]);
        return ret;
    }
    */
};
