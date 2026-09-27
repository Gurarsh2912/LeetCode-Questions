class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        if(source.size()==1) return source[0]==target[0];

        long long sum1 = 0;
        long long sum2 = 0;

        for(int x:source) sum1+=x;
        for(int x:target) sum2+=x;

        return sum1==sum2;
    }
};