class Solution {
public:
    int maxVowels(string s, int k) {
        int vowelCount = 0;
        int ans = 0;
        for(int i = 0; i<k; i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' ){
                vowelCount++;
            }
        }
        ans = vowelCount;
        int left = 0;
        int right = k;
        while(right<s.size()){
            if(s[left]=='a' || s[left]=='e' || s[left]=='i' || s[left]=='o' || s[left]=='u' ){
                vowelCount--;
            }
            left++;
            if(s[right]=='a' || s[right]=='e' || s[right]=='i' || s[right]=='o' || s[right]=='u' ){
                vowelCount++;
            }
            right++;

            ans = max(ans, vowelCount);
        }
        return ans;
        
    }
};