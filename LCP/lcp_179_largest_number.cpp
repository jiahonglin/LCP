class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        bool allzero=true;
        for(int i=0;i<n;i++){
            if(nums[i] != 0){
                allzero=false;
                break;
            }
        }
        if(allzero) return "0";
        vector<string> strnum;
        for(int i=0;i<n;i++){
            strnum.push_back(to_string(nums[i]));
        }
        sort(strnum.begin(),strnum.end(),compare);
        string ans="";
        for(int i=0;i<n;i++){
            ans+=strnum[i];
        }
        return ans;
    }
    static bool compare(string& str1, string& str2){
        string first = str1+str2;
        string second = str2+str1;
        int n = 0;
        while(n<first.size()){
            if(first[n] > second[n]){
                return true;
            }
            else if(first[n] < second[n]){
                return false;
            }
            n++;
        }
        return false;
    }
};
