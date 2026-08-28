class Solution {
public:
    string getSmallestString(int n, int k) {
        string s(n, 'a');
        k-=n;
        int i=n-1;
        while(k>0 && i>=0){
            int take = min(25, k);
            s[i] += take;
            k-=take;
            
            i--;
        }
        return s;
    }
};