class Solution {
public:
    
    vector<int> majorityElement(vector<int>& nums) {
        int limit = nums.size()/3;
        vector<int> sol;
        int vote1=0, vote2=0, votecnt1=0, votecnt2=0;
        for(int i=0;i<nums.size();i++){
            if(vote1==nums[i]){
                votecnt1++;
            }
            else if(vote2==nums[i]){
                votecnt2++;
            }
            else if(votecnt1 == 0){
                vote1 = nums[i];
                votecnt1 = 1;
            }
            else if(votecnt2 == 0){
                vote2 = nums[i];
                votecnt2 = 1;
            }
            else{
                votecnt1--;
                votecnt2--;
            }
        }
        votecnt1=0;
        votecnt2=0;
        for(int i=0;i<nums.size();i++){
            if(vote1 == nums[i]) votecnt1++;
            else if(vote2 == nums[i]) votecnt2++;
        }
        if(votecnt1 > limit) sol.push_back(vote1);
        if(votecnt2 > limit) sol.push_back(vote2);
        return sol;
    }

    /*Method 1*/
    /*
    vector<int> majorityElement(vector<int>& nums) {
        int s = nums.size()/3;
        map<int,int> m;
        vector<int> sol;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(auto it:m){
            if(it.second > s){
                sol.push_back(it.first);
            }
        }
        return sol;
    }
    */
};
