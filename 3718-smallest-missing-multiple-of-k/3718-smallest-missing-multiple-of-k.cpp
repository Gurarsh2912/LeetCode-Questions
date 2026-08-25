class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st(nums.begin(), nums.end());
        int i=1;
        while( true ){
            int num = k*i;
            if(st.find(num)==st.end()){
                return num;
            }
            i++;
        }
        return 0;
    }
};