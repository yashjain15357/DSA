class Solution {
public:
    double myPow(double x, int n) {
        // Use long long to prevent overflow when n is INT_MIN
        long long N = n; 
        
        // Handle negative exponents
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        
        double ans = 1.0;
        double current_product = x;
        
        // Exponentiation by squaring
        while (N > 0) {
            if (N % 2 == 1) {
                ans = ans * current_product;
            }
            current_product = current_product * current_product;
            N /= 2;
        }
        
        return ans;
    }
};