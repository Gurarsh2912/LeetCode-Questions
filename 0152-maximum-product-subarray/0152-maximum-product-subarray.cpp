class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxEnd = nums[0];
        int minEnd = nums[0];
        int oldMax;
        int oldMin;
        int ans = nums[0];

        for(int i = 1; i<nums.size(); i++){
            oldMax = maxEnd;
            oldMin = minEnd;
            maxEnd = max(nums[i], max(nums[i]*oldMax, nums[i]*oldMin));
            minEnd = min(nums[i], min(nums[i]*oldMax, nums[i]*oldMin));
            ans = max(ans, maxEnd);
        }
        return ans;
    }
};