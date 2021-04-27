class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadlock{deadends.begin(), deadends.end()};
        if(deadlock.count("0000") ) return -1;
        if(target == "0000") return 0;
        int res=0;
        unordered_set<string> visited{{"0000"}};
        queue<string> q;
        q.push("0000");
        while(!q.empty()){
            res++;
            for(int k=q.size();k>0;k--){
                string tmp=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    for(int j=-1;j<=1;j++){
                        if(j==0) continue;
                        string str = tmp;
                        str[i] = ((str[i]-'0')+j+10)%10 + '0';
                        if(str == target) return res;
                        if(!visited.count(str) && !deadlock.count(str)){
                            q.push(str);
                        }
                        visited.insert(str);
                    }
                }
            }
        }
        return -1;
    }
};
