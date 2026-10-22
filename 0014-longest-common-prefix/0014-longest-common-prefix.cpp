class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        int n = strs.size();
        for(int i = 1; i<n; i++){
            int idx = 0;
            while(idx < prefix.size() &&
                  idx < strs[i].size() &&
                  prefix[idx] == strs[i][idx]){
                idx++;
            }
            prefix = prefix.substr(0, idx);
            if(prefix.empty()) return "";
        }
        return prefix;
    }
};