class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int lastEnd = pairs[0][1];
        int ans = 1;
        for(int i = 1; i<pairs.size(); i++){
            if(lastEnd < pairs[i][0]){
                lastEnd = pairs[i][1];
                ans++;
            }
        }
        return ans;
    }
};