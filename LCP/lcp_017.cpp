class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<vector<char>> digitCharSet;
        vector<string> sol;
        string out;
        int maxlen = digits.length();
        if(maxlen > 0){
            generateDigitCharSet(digitCharSet,digits);
            generateComb(digitCharSet,sol,out,0,maxlen);
        }
        return sol;
    }
    void generateComb(vector<vector<char>>& digitCharSet, vector<string>& sol, string out, int numCnt, int maxlen){
        if(numCnt>=maxlen){
            sol.push_back(out);
            return;
        }
        for(int i=0;i<digitCharSet[numCnt].size();i++){
            out+=digitCharSet[numCnt][i];
            generateComb(digitCharSet,sol,out,numCnt+1,maxlen);
            out=out.substr(0,out.length()-1);
        }
    }

    void generateDigitCharSet(vector<vector<char>>& digitCharSet, string digits){
        for(int i=0;i<digits.length();i++){
            if(digits[i] == '2'){
                vector<char> charSet{'a','b','c'};
                digitCharSet.push_back(charSet);
            }
            else if(digits[i] == '3'){
                vector<char> charSet{'d','e','f'};
                digitCharSet.push_back(charSet);
            }
            else if(digits[i] == '4'){
                vector<char> charSet{'g','h','i'};
                digitCharSet.push_back(charSet);
            }
            else if(digits[i] == '5'){
                vector<char> charSet{'j','k','l'};
                digitCharSet.push_back(charSet);
            }
            else if(digits[i] == '6'){
                vector<char> charSet{'m','n','o'};
                digitCharSet.push_back(charSet);
            }
            else if(digits[i] == '7'){
                vector<char> charSet{'p','q','r','s'};
                digitCharSet.push_back(charSet);
            }
            else if(digits[i] == '8'){
                vector<char> charSet{'t','u','v'};
                digitCharSet.push_back(charSet);
            }
            else if(digits[i] == '9'){
                vector<char> charSet{'w','x','y','z'};
                digitCharSet.push_back(charSet);
            }
        }
    }
};
