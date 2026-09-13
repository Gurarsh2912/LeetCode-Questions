class Solution {
public:
    int scoreOfParentheses(string s) {
        stack <int> st;
        st.push(0);

        for(char ch : s){
            if(ch=='('){
                st.push(0);
            }

            else{
                int innerScore = st.top();
                st.pop();
                int currScore;

                if(innerScore == 0){
                    currScore = 1;
                }
                else{
                    currScore = 2*innerScore;
                }

                int outer = st.top();
                st.pop();
                st.push(outer+currScore);
            }
        }
        return st.top();
    }
};