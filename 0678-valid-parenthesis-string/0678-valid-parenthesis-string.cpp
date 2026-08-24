class Solution {
public:
    bool checkValidString(string s) {
        int minOpen = 0;
        int maxOpen = 0;
        int n = s.size();

        for(int i=0; i<n; i++){
            if(s[i]=='('){
                maxOpen++;
                minOpen++;
            }
            else if(s[i]==')'){
                minOpen--;
                maxOpen--;
            }
            else{
                minOpen--;
                maxOpen++;
            }

            if(maxOpen < 0) return false;
            if(minOpen < 0) minOpen=0;
        }

        return minOpen == 0;
    }
};