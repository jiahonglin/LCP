class Solution {
public:
    string getHint(string secret, string guess) {
        int m[256] = {0}, bulls = 0, cows = 0;
        for (int i = 0; i < secret.size(); ++i) {
            if (secret[i] == guess[i]) ++bulls;
            else {
                if (m[secret[i]]++ < 0) ++cows;
                if (m[guess[i]]-- > 0) ++ cows;
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
/*
    string getHint(string secret, string guess) {
        map<int,int> m;
        int bulls=0;
        int cows=0;
        for(int i=0;i<secret.length();i++){
            if(guess[i]==secret[i]){
                bulls++;
            }
            else{
                m[secret[i]-'0']++;
            }
        }
        for(int i=0;i<guess.length();i++){
            if(guess[i] != secret[i] && m[guess[i]-'0'] > 0){
                cows++;
                m[guess[i]-'0']--;
            }
        }
        return to_string(bulls)+"A"+to_string(cows)+"B";

    }
*/
};
