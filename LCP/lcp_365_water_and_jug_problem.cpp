class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        return (targetCapacity==0 || 
        (jug1Capacity+jug2Capacity >= targetCapacity && (targetCapacity % gcd(jug1Capacity, jug2Capacity))==0));
    }
    int gcd(int x, int y){
        return y==0?x:gcd(y,x%y);
    }
};
