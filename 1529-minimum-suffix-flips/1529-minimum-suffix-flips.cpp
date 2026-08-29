class Solution {
public:
    int minFlips(string target) {
        bool flipped = false;
        int ans = 0;
        
        for(int i = 0; i<target.size(); i++){
            char curr = flipped ? '1' : '0';
            if(target[i]!=curr){
                ans++;
                flipped = !flipped;
            }
        }
        return ans;   
    }
};