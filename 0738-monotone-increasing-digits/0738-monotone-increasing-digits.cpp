class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        int i;
        string s = to_string(n);
        int mark = s.size();
        for(i=s.size()-1; i>0; i--){
            if(s[i-1]>s[i]){
                s[i-1]--;
                mark = i;
            }
        }
        for(int j = mark; j<s.size(); j++){
            s[j]='9';
        }
        return stoi(s);
    }
};