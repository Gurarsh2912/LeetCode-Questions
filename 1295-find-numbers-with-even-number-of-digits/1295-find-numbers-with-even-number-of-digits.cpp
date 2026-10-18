class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i<n; i++){
            int size = to_string(nums[i]).size();
            if(size%2==0) ans++;
        }

        return ans;
    }
};