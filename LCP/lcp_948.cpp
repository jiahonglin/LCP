class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int upidx=0;
        int downidx=tokens.size()-1;
        int score=0;
        int cur = 0;
        sort(tokens.begin(),tokens.end());
        while(downidx >= upidx){
            while(downidx >= upidx && power>=tokens[upidx]){
                power -= tokens[upidx];
                upidx++;
                cur++;
                score = max(score,cur);
            }
            if(upidx > downidx || cur==0) break;
            cur--;
            power+=tokens[downidx];
            downidx--;
        }
        return score;
    }
};
