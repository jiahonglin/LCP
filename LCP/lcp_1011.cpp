class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(),weights.end());
        int right = accumulate(weights.begin(),weights.end(),0);
        while(left<right){
            int mid = left+(right-left)/2;
            int cnt = 1;
            int cur = 0;
            for(int w:weights){
                cur+=w;
                if(cur>mid){
                    cur=w;
                    cnt++;
                }
            }
            if(cnt > days) left = mid+1;
            else right = mid;
        }
        return left;
    }
};
