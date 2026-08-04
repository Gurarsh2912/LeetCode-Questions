class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int small = nums[0];
        int big = nums[0];
        vector<int> ans;
        for(auto &i : nums){
            small = min(small, i);
            big = max(big, i);
        }
        int i=0;
        while(small<=big){
            if(i<nums.size() && nums[i]==small){
                small++;
                i++;
            }
            else if(i<nums.size() && nums[i]<small){
                i++;
            }
            else{
                ans.push_back(small);
                small++;
            }
        }
        return ans;
    }
};