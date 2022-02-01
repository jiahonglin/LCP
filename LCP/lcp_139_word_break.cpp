class Solution {
public:
    
    /*Dynamic programming*/
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length()+1,false);
        unordered_set<string> wordset(wordDict.begin(),wordDict.end());
        dp[0]=true;
        for(int i=0;i<dp.size();i++){
            for(int j=0;j<i;j++){
                if(dp[j] && wordset.count(s.substr(j,i-j))){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp.back();
    }
    
    /*DFS*/
    /*
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordset(wordDict.begin(),wordDict.end());
        vector<int> memory(s.length(),-1);
        return check(s,wordset,0, memory);
    }
    bool check(string s, unordered_set<string>& wordset, int start, vector<int>& memory){
        if(start >= s.length()) return true;
        if(memory[start] != -1) return memory[start];
        for(int i=start+1;i<=s.length();i++){
            if(wordset.count(s.substr(start,i-start)) && check(s,wordset,i,memory)){
                return memory[start]=1;
            }
        }
        return memory[start]=0;
    }
    */
};
