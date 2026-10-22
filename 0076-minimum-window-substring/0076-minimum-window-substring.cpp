
class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";

        unordered_map<char, int> countT, window;

        for(char c : t) countT[c]++;

        int have = 0, need = countT.size();
        int l = 0, start = 0, minLen = INT_MAX;

        for(int r = 0; r < s.size(); r++) {
            window[s[r]]++;

            if(countT.count(s[r]) &&
               window[s[r]] == countT[s[r]]) {
                have++;
            }

            while(have == need) {
                if(r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }

                window[s[l]]--;

                if(countT.count(s[l]) &&
                   window[s[l]] < countT[s[l]]) {
                    have--;
                }

                l++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
