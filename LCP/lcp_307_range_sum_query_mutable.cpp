class NumArray {
public:
    vector<int> element;
    vector<int> block;
    int blockLen=0;
    NumArray(vector<int>& nums) {
        element = nums;
        double root = sqrt(element.size());
        blockLen = ceil(element.size()/root);
        block.resize(blockLen);
        for(int i=0;i<element.size();i++){
            block[i/blockLen]+=element[i];
        }
    }
    
    void update(int index, int val) {
       int blockIdx = index/blockLen;
       block[blockIdx]+=val-element[index];
       element[index] = val;
    }
    
    int sumRange(int left, int right) {
        int start = left/blockLen;
        int end = right/blockLen;
        int sum=0;
        if(start == end){
            for(int i=left;i<=right;i++){
                sum+=element[i];
            }
            return sum;
        }
        for(int i=left;i<(start+1)*blockLen;i++){
            sum+=element[i];
        }
        for(int i=start+1;i<end;i++){
            sum+=block[i];
        }
        for(int i=end*blockLen;i<=right;i++){
            sum+=element[i];
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
