class Solution {
public:
    int hIndex(vector<int>& citations) {
        int paperNum = citations.size();
        int left = 0;
        int right = paperNum-1;
        while(left <= right){
            int mid = (left+right)/2;
            if(citations[mid] == paperNum-mid) return paperNum-mid;
            else if(citations[mid] > paperNum-mid) right=mid-1;
            else left=mid+1;
        }
        return paperNum-left;
    }
};
