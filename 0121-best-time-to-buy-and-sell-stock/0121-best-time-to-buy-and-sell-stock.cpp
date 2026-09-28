class Solution {
public:
    int maxProfit(vector<int>& p) {
        int bb = p[0];
        int ans = 0;
        for(int x : p){
            ans = max(ans, x-bb);
            bb = min(bb, x);
        }      
        return ans;
    }
};