class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans=0;
        vector<int> mask(words.size(),0);
        for(int i=0;i<words.size();i++){
            for(auto c:words[i]) mask[i] |= 1<<c-'a';
            for(int j=0;j<i;j++){
                if(!(mask[i]&mask[j])){
                    int len = words[i].length()*words[j].length();
                    ans=len>ans?len:ans;
                }
            }
        }
        return ans;
    }
/*
    int maxProduct(vector<string>& words) {
        int ans=0;
        vector<int> mask(words.size(),0);
        for(int i=0;i<words.size()-1;i++){
            for(int j=i+1;j<words.size();j++){
                int len1 = words[i].length();
                int len2 = words[j].length();
                
                if(mask[i]==0){
                    for(auto c:words[i]) mask[i] |= 1<<c-'a';
                }
                if(mask[j]==0){
                    for(auto c:words[j]) mask[j] |= 1<<c-'a';
                }
                if(!(mask[i]&mask[j])){
                    ans=(len1*len2>ans)?len1*len2:ans;
                }
            }
        }
        return ans;
    }
*/
};
