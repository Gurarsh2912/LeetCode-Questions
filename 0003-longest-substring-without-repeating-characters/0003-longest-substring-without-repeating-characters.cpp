class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        unordered_set<char> charSet;
        int ans = 0;

        while(right<s.size()){
            if(charSet.find(s[right])==charSet.end()){
                charSet.insert(s[right]);
                ans = max(ans, right-left+1);
                right++;
            }
            else{
                charSet.erase(s[left]);
                left++;
            }
        }
        return ans;
    }
};