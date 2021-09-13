class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int right = people.size()-1;
        int left = 0;
        int sol=0;
        while(left <= right){
            if(people[left]+people[right] <= limit) ++left;
            right--;
            sol++;
        }
        
        return sol;
    }
};
