class Solution {
public:
    /*Method 1*/
    int lengthOfLongestSubstring(string s) {
        map<int,int> m;
        int i=0, left=-1;
        int sol=0;
        while(i<s.length()){
            if(m.count(s[i]) && m[s[i]] > left){
                left=m[s[i]];
            }
            m[s[i]]=i;
            sol=max(sol,i-left);
            i++;
        }
        return sol;
    }

    /*Method 2*/
    /*
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        int maxCnt=0;
        int i=0,j=0;
        while(j<s.length()){
            m[s[j]]++;
            if(j-i+1 == m.size()){
                maxCnt=max(maxCnt,j-i+1);
            }
            else if(j-i+1 > m.size()){
                while(j-i+1 > m.size()){
                    m[s[i]]--;
                    if(m[s[i]]==0)
                        m.erase(s[i]);
                    if(j-i+1 == m.size()){
                        maxCnt=max(maxCnt,j-i+1);
                    }
                    i++;
                }
            }
            j++;
        }
        return maxCnt;
    }
    */
};
