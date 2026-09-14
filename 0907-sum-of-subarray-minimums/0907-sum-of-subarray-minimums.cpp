class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> left(n);
        vector<int> right(n);
        int MOD = 1e9 + 7;

        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            left[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long ans = 0;

        for(int i = 0; i<n; i++){
            long long contri = 1LL * arr[i] * (i-left[i]) * (right[i]-i);
            ans = (ans+contri) % MOD;
        }

        return (int) ans;

    }
};