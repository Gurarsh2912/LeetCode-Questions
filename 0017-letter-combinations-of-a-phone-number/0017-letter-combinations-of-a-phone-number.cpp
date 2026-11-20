class Solution {
public:
    vector<string> mapping = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void solve(string &digits, int idx, string &path, vector<string> &ans) {

        if(idx == digits.size()) {
            ans.push_back(path);
            return;
        }
        string letters = mapping[digits[idx] - '0'];

        for(char ch : letters) {
            path.push_back(ch);          
            solve(digits, idx + 1, path, ans); 
            path.pop_back(); 
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;

        if(digits.empty()) return ans;

        string path = "";
        solve(digits, 0, path, ans);

        return ans;
    }
};