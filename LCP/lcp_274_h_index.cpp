class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        reverse(citations.begin(),citations.end());
        for(int i=0;i<citations.size();i++){
            if(citations[i] <= i) return i;
        }
        return citations.size();
    }
/*
    int hIndex(vector<int>& citations) {
        int papers = citations.size();
        while(papers > 0){
            int cnt=0;
            for(int i=0;i<citations.size();i++){
                if(citations[i] >= papers) cnt++;
            }
            if(cnt >= papers) break;
            papers--;
        }
        return papers;
    }
*/
};
