class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        unordered_map<char, int> m;
        int n = s.size();
        for(int i = 0; i<n; i++){
            m[s[i]] = i;
        }
        int start = 0;
        int maxIdx = 0;

        for(int i=0; i<n; i++){
            maxIdx = max(maxIdx, m[s[i]]);

            if(i == maxIdx){
                ans.push_back(i-start+1);
                start = i+1;
            }
        }
        return ans;
    }
};