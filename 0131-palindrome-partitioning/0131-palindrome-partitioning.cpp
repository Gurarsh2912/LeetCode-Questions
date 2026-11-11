class Solution {
public:
    bool isPal(string s){
        string s1 = s;
        reverse(s1.begin(), s1.end());
        return s1==s;
    }

    void helper(string s, vector<string> &parts, vector<vector<string>>& ans){
        if(s.size()==0){
            ans.push_back(parts);
            return;
        }

        for(int i = 0; i<s.size(); i++){
            string part = s.substr(0, i+1);
            if(isPal(part)){
                parts.push_back(part);
                helper(s.substr(i+1), parts, ans);
                parts.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> parts;
        helper(s, parts, ans);
        return ans;
    }
};