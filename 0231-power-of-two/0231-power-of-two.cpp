class Solution {
public:
    bool isPowerOfTwo(int n) {
        // Base cases
        if (n <= 0) return false;
        if (n == 1) return true;
        
        // If the number is odd, it cannot be a power of two
        if (n % 2 != 0) return false;
        
        // Recursive step: divide by 2 and check again
        return isPowerOfTwo(n / 2);
    }
};