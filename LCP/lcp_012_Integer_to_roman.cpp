class Solution {
public:
    string intToRoman(int num) {
        map<int, string> m;
        m.insert({1,"I"});
        m.insert({5,"V"});
        m.insert({10,"X"});
        m.insert({50,"L"});
        m.insert({100,"C"});
        m.insert({500,"D"});
        m.insert({1000,"M"});
        m.insert({4,"IV"});
        m.insert({9,"IX"});
        m.insert({40,"XL"});
        m.insert({90,"XC"});
        m.insert({400,"CD"});
        m.insert({900,"CM"});
        map<int,string>::reverse_iterator rit;
        string sol="";
        for(rit=m.rbegin();rit!=m.rend();rit++){
            int fac=rit->first;
            string s=rit->second;
            while(num >= fac){
                num-=fac;
                sol+=s;
            }
        }
        return sol;
    }
};
