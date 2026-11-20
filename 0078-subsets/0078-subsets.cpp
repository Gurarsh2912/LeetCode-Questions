class Solution {
public:
    void helper(vector<vector<int>> &ans, vector<int> &nums, vector<int> temp, int i){
        if(i==nums.size()){
            ans.push_back({temp});
            return;
        }
        temp.push_back(nums[i]);
        helper(ans, nums, temp, i+1);
        temp.pop_back();
        helper(ans, nums, temp, i+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(ans, nums, {}, 0);
        return ans;
    }
};