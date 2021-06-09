class Solution {
public:
    map<int,int> rec;
    int fib(int n) {
        if(rec.count(n) != 0) return rec[n];
        int result;
        if(n<2){
            result = n;
        }
        else{
            result = fib(n-1)+fib(n-2);
        }
        rec.insert(pair<int,int>(n,result));
        return result;
    }
};
