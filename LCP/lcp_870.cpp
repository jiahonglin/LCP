class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size());
        int left=0,right=nums1.size()-1;
        priority_queue<pair<int,int>> q;
        sort(nums1.begin(),nums1.end());
        for(int i=0;i<nums2.size();i++) q.push({nums2[i],i});
        while(!q.empty()){
            int val=q.top().first;
            int idx=q.top().second;
            q.pop();
            if(nums1[right] <= val){
                res[idx]=nums1[left++];
            }
            else{
                res[idx]=nums1[right--];
            }
        }
        return res;
    }
    /**Method2**/
    /*
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> st(nums1.begin(),nums1.end());
        vector<int> res(nums1.size());
        for(int i=0;i<nums2.size();i++){
            auto it=*st.rbegin()<=nums2[i]?st.begin():st.upper_bound(nums2[i]);
            res[i] = *it;
            st.erase(it);
        }
        return res;
    }
    */
};
