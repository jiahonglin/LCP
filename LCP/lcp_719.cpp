class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        /*
        vector<int> cnt(1000000,0);
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                ++cnt[abs(nums[i]-nums[j])];
            }
        }
        for(int m=0;m<cnt.size();m++){
            if(k<=cnt[m]) return m;
            k-=cnt[m];
        }
        return 0;
        */
        sort(nums.begin(),nums.end());
        int left=0,right=nums.back()-nums[0];
        while(left < right){
            int mid = left+(right-left)/2;
            int cnt=0;
            int start=0;
            for(int i=0;i<nums.size();i++){
                while(start < nums.size() && nums[i]-nums[start] > mid) start++;
                cnt+=i-start;
            }
            if(cnt < k) left=mid+1;
            else right=mid;
        }
        return right;
    }
};
