class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> m;
        int n = s.size();
        for(int i=0; i<n; i++){
            m[s[i]]++;
        }
        unordered_set<int> used;
        int dels = 0;

        for(auto &[ch, freq]: m){
            while(freq>0 && used.find(freq)!=used.end()){
                freq--;
                dels++;
            }
            if(freq>0){
                used.insert(freq);

            }
        }
        return dels;
    }
};