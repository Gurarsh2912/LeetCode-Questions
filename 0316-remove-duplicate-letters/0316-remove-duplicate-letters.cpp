class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26, 0);
        vector<bool> used(26, false); 
        stack <int> st;

        for(char ch : s){
            freq[ch-'a']++;
        }

        for(char ch : s){
            int curr = ch-'a';
            freq[curr]--;
            if(used[curr]) continue;

            while(!st.empty() && st.top()>curr && freq[st.top()]>0){
                used[st.top()] = false;
                st.pop();
            }

            st.push(curr);
            used[curr] = true;
        }

        string ans = "";
        while(!st.empty()){
            ans+=char(st.top()+'a');
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};