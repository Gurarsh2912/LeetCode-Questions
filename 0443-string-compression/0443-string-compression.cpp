class Solution {
public:
    int compress(vector<char>& chars) {
        int idx = 0;
        int n = chars.size();
        int count = 0;
        for(int i = 0; i<n; i++){
            count = 0;
            char ch = chars[i];
            while(i<n && ch==chars[i]){
                count++;
                i++;
            }
            i--;
            if(count==1){
                chars[idx++] = ch;
            }

            else{
                chars[idx++] = ch;
                string str = to_string(count);
                for(char dig : str){
                    chars[idx++] = dig;
                }
            }
        }
        chars.resize(idx);
        return idx;
    }
};