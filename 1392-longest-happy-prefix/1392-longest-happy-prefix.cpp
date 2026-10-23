class Solution {
public:
    string longestPrefix(string s) {
        int pre = 0, suf = 1;
        vector<int> lps(s.size(), 0);

        while(suf<s.size()){
            if(s[pre]==s[suf]){
                lps[suf] = pre+1;
                suf++;
                pre++;
            }

            else{
                if(pre!=0)  pre = lps[pre-1];

                else suf++;
            }
        }
        return s.substr(0, lps[s.size()-1]);
    }
};