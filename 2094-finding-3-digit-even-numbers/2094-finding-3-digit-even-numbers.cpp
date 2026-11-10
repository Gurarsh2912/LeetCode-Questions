class Solution {
public:

    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans;
        vector<int> freq(10, 0);
        for(int x : digits){
            freq[x]++;
        }

        for(int num = 100; num<999; num+=2){
            int h = num / 100;
            int t = (num / 10) % 10;
            int u = num % 10;
            int need[10] = {0};

            need[h]++;
            need[t]++;
            need[u]++;

            bool valid = true;

            for(int i = 0; i < 10; i++) {
                if(need[i] > freq[i]) {
                    valid = false;
                    break;
                }
            }

            if(valid) {
                ans.push_back(num);
            }
        }
        return ans;
    }
};