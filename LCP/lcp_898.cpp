class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> s;
        for(int i=0;i<arr.size();i++){
            s.insert(arr[i]);
            for(int j=i-1;j>=0;j--){
                if((arr[j]|arr[i]) == arr[j])
                    break;
                arr[j]|=arr[i];
                s.insert(arr[j]);
            }
        }
        return s.size();
    }
};
