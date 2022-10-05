class Solution {
public:
    string simplifyPath(string path) {
        int idx=0;
        stack<string> dirs;
        string result="";

        for(int idx=0; idx < path.length();idx++){
            if(path[idx] == '/') continue;
            string directory="";
            while(idx < path.length() && path[idx]!='/') {
                directory+=path[idx++];
            }
            if(directory == "." || directory.length()==0){}
            else if (directory ==".."){
                if(!dirs.empty()){
                    dirs.pop();
                }
            }
            else{
                dirs.push(directory);
            }
        }
        if(dirs.empty()) return "/";
        while(!dirs.empty()){
            result="/"+dirs.top()+result;
            dirs.pop();
        }
        return result;
    }
    
    /*
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
    */
};
