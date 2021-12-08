class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen=0,n=s.length(),start=0;
        for(int i=0;i<n;i++){
            int left=i, right=i;
            while(right+1 < n && s[right]==s[right+1]) right++;
            while(left-1 >= 0 && right+1 < n && s[left-1]==s[right+1]){left--;right++;}
            if(right-left+1 > maxLen){
                maxLen=right-left+1;
                start=left;
            }
        }
        return s.substr(start,maxLen);
    }
};
