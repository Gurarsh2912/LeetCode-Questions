class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            if(nums[i] < 0 && k>0){
                nums[i]*=-1;
                k--;
            }
        }
        int sum = 0;
        for(int el : nums){
            sum+=el;
        }
        sort(nums.begin(), nums.end());
        if(k%2!=0){
            sum-=2*nums[0];
        }
        return sum;
    }
};