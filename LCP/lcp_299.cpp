class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int> m;
        unordered_map<char,int> g;
        int bulls=0;
        int cows=0;
        int n=secret.length();
        int i =0;
        while(i<n){
            if(secret[i]==guess[i]){
                bulls++;
                i++;
                continue;
            }
            m[secret[i]]++;
            g[guess[i]]++;
            i++;
        }
        for(auto it:m){
            int x=min(g[it.first],it.second);
            cows+=x;
        }
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
    /*Method 2*/
    /*
    string getHint(string secret, string guess) {
        unordered_map<char,int> m;
        unordered_map<char,int> g;
        int bulls=0;
        int cows=0;
        for(char c:secret) m[c]++;
        for(char c:guess) g[c]++;

        for(int i=0;i<secret.length();i++){
            if(secret[i] == guess[i]){
                bulls++;
                m[guess[i]]--;
                g[guess[i]]--;
            }
        }
        for(int i=0;i<secret.length();i++){
            if(g[guess[i]]>0 && m[guess[i]] > 0){
                m[guess[i]]--;
                g[guess[i]]--;
                cows++; 
            }
        }
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
    */
};
