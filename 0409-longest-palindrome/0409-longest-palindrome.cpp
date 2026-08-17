class Solution {
public:
    int longestPalindrome(string s) {
        int ans = 0;
        bool hasOdd = false;
        unordered_map<char, int> m;
        int n = s.size();
        for(int i=0; i<n; i++){
            m[s[i]]++;
        }

        for(auto& [c, num] : m){
            ans += (num / 2) * 2;

            if(num % 2 != 0){
                hasOdd = true;
            }
        }
        return hasOdd ? ans+1 : ans;
    }
};