class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));

        for(int gap = 2; gap<m; gap++){
            for(int i = 0; i+gap<m; i++){
                int j = i+gap;
                int currBest = INT_MAX;
                for(int k = i+1; k<j; k++){
                    currBest = min(currBest, cuts[j]-cuts[i]+dp[i][k]+dp[k][j]);
                }
            dp[i][j] =currBest;
            }
        }
        return dp[0][m-1];
    }
};