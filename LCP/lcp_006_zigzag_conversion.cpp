class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.length();
        string sol;
        for(int i=0;i<numRows;i++){
            int index = i;
            while(index < len){
                sol+=s[index];
                if(i == 0 || i == numRows-1){
                    index+=2*(numRows-1);
                    if(numRows == 1) index++;
                    continue;    
                }
                if(index+2*(numRows-i-1) < len){
                    index+=2*(numRows-i-1);
                    sol+=s[index];
                    index+=2*i;
                }
                else{
                    break;
                }
            }
        }
        return sol;
    }
};
