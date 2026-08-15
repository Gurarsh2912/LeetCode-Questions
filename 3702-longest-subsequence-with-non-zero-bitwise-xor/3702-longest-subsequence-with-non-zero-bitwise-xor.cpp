class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        bool nonZero = false;
        int ans = 0;
        for(int num : nums){
            ans = ans ^ num;
            if(num!=0){
                nonZero = true;
            }
        }

        if(ans!=0){
            return nums.size();
        }
        else{
            if(nonZero){
                return nums.size()-1;
            }
            else{
                return 0;
            }
        }
        return 0;
    }
};