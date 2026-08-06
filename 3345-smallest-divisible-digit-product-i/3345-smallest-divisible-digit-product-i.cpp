class Solution {
public:
    int product(int n){
        int val = 1;
        while(n>0){
            val*=n%10;
            n/=10;   
        }
        return val;
    }

    int smallestNumber(int n, int t) {
        while(product(n)%t!=0){
            n++;
        }
        return n;
    }
};