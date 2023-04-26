class Solution {
public:
/*
    void rotate(vector<int>& nums, int k) {
        if(k==0) return;
        while(k>nums.size()) k=k%nums.size();
        vector<int> v(nums.size(),0);
        int a=0,b=nums.size()-k;
        for(int i=0;i<nums.size();i++){
            if(b<=nums.size()-1){
                v[i]=nums[b];
                b++;
            }
            else{
                v[i]=nums[a];
                a++;
            }
        }
        nums=v;
    }
*/
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};
