class Solution {
public:
    bool isValid(int mid, vector<int>& nums, int k){
        int sum = 0;
        int num = 0;
        for(int x : nums){
            if(x+sum <= mid){
                sum+=x;
            }
            else{
                sum = x;
                num++;
            }
        }
        return num<k;
    }

    int splitArray(vector<int>& nums, int k) {
        int st = *max_element(nums.begin(), nums.end()), end = 0;
        int ans = -1;
        for(int x : nums){
            end+=x;
        }
        while(st<=end){
            int mid = st+(end-st)/2;
            if(isValid(mid, nums, k)){
                ans = mid;
                end = mid-1;
            }
            else{
                st = mid+1;
            }
        }
        return ans;
    }
};