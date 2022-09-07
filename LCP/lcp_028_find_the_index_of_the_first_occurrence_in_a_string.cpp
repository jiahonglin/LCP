class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.find(needle);
        if(n == std::string::npos) return -1;
        else return n;
    }
    /*
    int strStr(string haystack, string needle) {
        int m = haystack.length();
        int n = needle.length();
        if(m < n) return -1;
        int i=0,j=0,index=-1;
        while(i <= (m-n) && j < n){
            if(haystack[i+j] == needle[j]){
                j++;
            }
            else{
                i++;
                j=0;
            }
        }
        if(j == n) return i;
        else return -1;
    }
    */
};
