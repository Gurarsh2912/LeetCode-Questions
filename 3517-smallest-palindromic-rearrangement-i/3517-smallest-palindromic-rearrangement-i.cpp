class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);
        for(int i = 0; i<s.size(); i++){
            freq[s[i]-'a']++;
        }
        string left;
        string mid;

        for(int j=0; j<26; j++){
            if(freq[j]%2!=0){
                mid = j+'a';
            }
            if(freq[j]!=0){
                for(int k=0; k<(freq[j]/2); k++){
                    left.push_back('a'+j);
                }
            }
        }
        string right = left;
        reverse(right.begin(), right.end());
        return left + mid + right;
    }
};