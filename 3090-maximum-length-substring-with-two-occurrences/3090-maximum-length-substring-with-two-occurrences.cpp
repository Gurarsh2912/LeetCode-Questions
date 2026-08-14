class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map <int, int> m;
        int left = 0;
        int ans = 0;
        m[s[left]] = 1;
        for(int right = 1; right<s.size(); right++){
            m[s[right]]++;
            while(m[s[right]]>2){
                m[s[left]]--;
                left++;
            }
            ans = max(ans, right-left+1);
        }
        return ans;
    }
};