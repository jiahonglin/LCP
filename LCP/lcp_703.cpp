class KthLargest {

public:
    KthLargest(int k, vector<int>& nums) {
        k_ = k;
        for(int i = 0;i < nums.size();i++)
        {
            q.push(nums[i]);
            if(q.size() > k_)
            {
                q.pop();
            }
        }
    }
    
    int add(int val) {
        q.push(val);
        if(q.size() > k_)
        {
            q.pop();
        }
        return q.top();
    }
private:
    priority_queue<int,vector<int>,greater<int>> q;
    int k_;
    
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
