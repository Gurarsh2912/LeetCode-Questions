class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        int keptMax = neededTime[0];
        int n = neededTime.size();
        for(int i=1; i<n; i++){
            if(colors[i-1]==colors[i]){
                ans += min(keptMax, neededTime[i]);
                keptMax = max(keptMax, neededTime[i]);
            }
            else{
                keptMax = neededTime[i];
            }
        }
        return ans;
    }
};