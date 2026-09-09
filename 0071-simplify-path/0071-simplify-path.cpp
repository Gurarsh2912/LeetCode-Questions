class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dirs;
        stringstream ss(path);
        string part;

        while(getline(ss, part, '/')) {
            if(part == "" || part == "."){
                continue;
            }
            else if(part == ".."){
                if(dirs.size()>0){
                    dirs.pop_back();
                }
            }
            else{
                dirs.push_back(part);
            }
        }

        string ans = "";

        for(string str : dirs){
            ans+="/" + str;
        }
        if(ans==""){
            return "/";
        }
        return ans;

    }
};