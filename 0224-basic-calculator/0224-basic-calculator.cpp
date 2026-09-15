class Solution {
public:
    int calculate(string s) {
        long long num = 0;
        long long sign = 1;
        long long result = 0;

        stack<long long> st;

        for(char ch : s) {

            if(isdigit(ch)) {
                num = num * 10 + (ch - '0');
            }

            else if(ch == '+' || ch == '-') {
                result += sign * num;
                num = 0;

                sign = (ch == '+') ? 1 : -1;
            }

            else if(ch == '(') {
                st.push(result);
                st.push(sign);

                result = 0;
                sign = 1;
            }

            else if(ch == ')') {
                result += sign * num;
                num = 0;

                long long prevSign = st.top();
                st.pop();

                long long prevResult = st.top();
                st.pop();

                result = prevResult + prevSign * result;
            }
        }

        result += sign * num;

        return (int)result;
    }
};