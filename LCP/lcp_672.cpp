class Solution {
public:
    int flipLights(int n, int presses) {
        n=(n<=6)?n:(6+n%6);
        unordered_set<int> s;
        queue<int> q;
        int start = 1<<n;
        q.push(start);
        for(int i=0;i<presses;i++){
            int len = q.size();
            s.clear();
            for(int j = 0;j<len;j++){
                int t = q.front();q.pop();
                vector<int> next{button1(t,n), button2(t,n), button3(t,n), button4(t,n)};
                for(int num:next){
                    if(s.count(num)) continue;
                    q.push(num);
                    s.insert(num);
                }
            }
        }
        return q.size();
    }
    /*flip all*/
    int button1(int t, int n){
        int rtn=t;
        for(int i=0;i<n;i++){
            rtn^=(1<<i);
        }
        return rtn;
    }
    /*Flip even*/
    int button2(int t, int n){
        int rtn=t;
        for(int i=1;i<n;i+=2){
            rtn^=(1<<i);
        }
        return rtn;
    }
    /*Flip odd*/
    int button3(int t, int n){
        int rtn=t;
        for(int i=0;i<n;i+=2){
            rtn^=(1<<i);
        }
        return rtn;
    }
    /*Flip 3k+1*/
    int button4(int t, int n){
        int rtn=t;
        for(int i=0;i<n;i+=3){
            rtn^=(1<<i);
        }
        return rtn;
    }
};
