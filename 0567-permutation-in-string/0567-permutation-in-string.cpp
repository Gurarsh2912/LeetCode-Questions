class Solution {
public:
    bool isSame(int freq1[]){
        for(int i=0; i<26; i++){
            if (freq1[i]!=0){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        if(m>n) return false;

        int freq[26] = {0};
        for(int i = 0; i<m; i++){
            freq[s1[i]-'a']++;
            freq[s2[i]-'a']--;
        }

        if(isSame(freq)) return true;

        for(int i = m; i<n; i++){
            freq[s2[i]-'a']--;
            freq[s2[i-m]-'a']++;

            if(isSame(freq)) return true;
        }        

        return false;
    }
};