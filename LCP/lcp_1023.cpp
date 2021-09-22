class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        for(string str:queries){
            if(str.length() < pattern.length()){
                ans.push_back(false);
                continue;
            }
            int idx=0;
            int i =0;
            bool alreadyPush = false;
            for(i=0;i<str.length()&&idx<pattern.length();i++){
                if(str[i] == pattern[idx]){
                    idx++;
                }
                else if(str[i] < 'a'){
                    ans.push_back(false);
                    alreadyPush = true;
                    break;
                }
            }
            
            if(idx==pattern.length()){
                if(i<str.length()){
                    for(int j=i;j<str.length();j++){
                        if(str[j] < 'a'){
                            ans.push_back(false);
                            alreadyPush = true;
                            break;
                        }
                    }
                }
            } 
            if(alreadyPush == false){
                if(idx == pattern.length()){
                    ans.push_back(true);
                }
                else{
                    ans.push_back(false);
                }
            }
        }
        return ans;
    }
};
