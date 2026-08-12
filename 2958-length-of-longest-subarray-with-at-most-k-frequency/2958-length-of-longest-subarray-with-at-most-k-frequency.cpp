class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        unordered_map<int, int> m;
        int i = 0;
        for(int j = 0; j<n; j++){
            if(m.find(nums[i])==m.end()){
                m[nums[j]]=1;
            }
            else{
                m[nums[j]]+=1;
            }
            while (m[nums[j]] > k){
                m[nums[i]]-=1;
                i++;
            }

            ans = max(ans, j-i+1);
        }

        return ans;
    }
};