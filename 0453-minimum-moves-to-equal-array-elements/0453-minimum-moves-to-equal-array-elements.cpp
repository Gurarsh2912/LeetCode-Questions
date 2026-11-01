class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans = 0;
        int mn = INT_MAX;

        for(int x : nums){
            mn = min(mn, x);
        }

        for(int x : nums){
            ans+=x-mn;
        }

        return ans;
    }
};