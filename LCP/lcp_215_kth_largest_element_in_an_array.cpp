class Solution {
public:
    
    /*Method 6: Merge sort*/
    /*O(nlogn)*/
    int findKthLargest(vector<int>& nums, int k){
        int n = nums.size();
        mergeSort(nums, 0, n-1);
        return nums[n-k];
    }
    void mergeSort(vector<int>& nums, int front, int end){
        if(front < end){
            int mid=front+(end-front)/2;
            mergeSort(nums, front, mid);
            mergeSort(nums, mid+1, end);
            merge(nums, front, mid, end);
        }
    }
    void merge(vector<int>& nums, int front, int mid, int end){
        vector<int> leftPart(nums.begin()+front, nums.begin()+mid+1);
        vector<int> rightPart(nums.begin()+mid+1, nums.begin()+end+1);
        leftPart.push_back(INT_MAX);
        rightPart.push_back(INT_MAX);
        int l_idx=0, r_idx=0;
        for(int i=front;i<=end;i++){
            if(leftPart[l_idx] < rightPart[r_idx]){
                nums[i]=leftPart[l_idx];
                l_idx++;
            }
            else{
                nums[i]=rightPart[r_idx];
                r_idx++;
            }
        }
    }
    /*Method 5: Quick sort*/
    /*AVG: O(nlogn), Worst: O(n^2)*/
    /*
    int findKthLargest(vector<int>& nums, int k){
        int n = nums.size();
        quickSort(nums,0,n-1);
        return nums[n-k];
    }
    void quickSort(vector<int>& nums, int front, int end){
        if(front < end){
            int pivot = partition(nums, front, end);
            quickSort(nums, front, pivot-1);
            quickSort(nums, pivot+1, end);
        }
    }
    int partition(vector<int>& nums, int front, int end){
        int pivot = nums[end];
        int cut = front;
        for(int i=front;i<end;i++){
            if(nums[i] < pivot){
                swap(nums[i],nums[cut]);
                cut++;
            }
        }
        swap(nums[end], nums[cut]);
        return cut;
    }
    void swap(int& a, int& b){
        int tmp=a;
        a=b;
        b=tmp;
    }
    */
    /*Method 4: Insertion sort*/
    /*O(n^2)*/
    /*
    int findKthLargest(vector<int>& nums, int k){
        int n = nums.size();
        for(int i = 0 ; i < n-1 ; i++){
            for(int j = i+1 ; j > 0 ; j--){
                if(nums[j] < nums[j-1]){
                    swap(nums[j],nums[j-1]);
                }
            }
        }
        return nums[n-k];
    }
    void swap(int& a, int& b){
        int tmp=a;
        a=b;
        b=tmp;
    }
    */
    /*Method 3: selection sort*/
    /*O(n^2)*/
    /*
    int findKthLargest(vector<int>& nums, int k){
        int n = nums.size();
        for(int i = 0 ; i < n-1 ; i++){
            int minIdx = i;
            for(int j = i+1 ; j < n ; j++){
                if(nums[minIdx] > nums[j]) minIdx=j;
            }
            swap(nums[i],nums[minIdx]);
        }
        return nums[n-k];
    }
    void swap(int& a, int& b){
        int tmp=a;
        a=b;
        b=tmp;
    }
    */
    /*Method 2: bubble sort*/
    /*O(n^2)*/
    /*
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            for(int j = i+1 ; j < n ; j++){
                if(nums[i] > nums[j]){
                    swap(nums[i],nums[j]);
                }
            }
        }
        return nums[n-k];
    }
    void swap(int& a, int& b){
        int tmp=a;
        a=b;
        b=tmp;
    }
    */

    /*Method 1 : use c++ std method*/
    /*
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()-k];
    }
    */
};
