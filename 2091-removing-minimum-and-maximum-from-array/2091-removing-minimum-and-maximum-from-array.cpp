class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int high = nums[0], low = nums[0];
        int highInd = 0, lowInd = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] > high) {
                high = nums[i];
                highInd = i;
            }

            if(nums[i] < low) {
                low = nums[i];
                lowInd = i;
            }
        }

        int case1 = max(lowInd, highInd) + 1;

        int case2 = n - min(highInd, lowInd);

        int case3;
        if(highInd > lowInd) {
            case3 = (lowInd + 1) + (n - highInd);
        } 
        else {
            case3 = (highInd + 1) + (n - lowInd);
        }

        return min({case1, case2, case3});
    }
};