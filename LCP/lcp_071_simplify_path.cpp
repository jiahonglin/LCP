class Solution {
public:
    string simplifyPath(string path) {
        
        string directory, result;
        stack<string> s;
        path+="/";
        for(int i=0;i<path.length();i++){
            if(path[i] != '/'){
                directory += path[i];
            }
            else{
                if(directory.length() == 0 || directory==".") {}
                else if(directory == ".."){
                    if(!s.empty())
                        s.pop();
                }
                else{
                    s.push(directory);
                }
                directory="";
            }
        }
        if(s.empty()) return "/";
        while(!s.empty()){          
            result = "/"+ s.top() + result;
            s.pop();
        }
        return result;
    }
};
