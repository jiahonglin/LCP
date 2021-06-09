class Solution {
public:
    map<int,int> steps;
    int climbStairs(int n) {
        if(steps.count(n) != 0) return steps[n];
        int stepCount;
        if(n<=2){
            stepCount = n;
        }
        else{
            stepCount = climbStairs(n-1)+climbStairs(n-2);
        }
        steps.insert(pair<int,int>(n,stepCount));
        return stepCount;
    }
};
