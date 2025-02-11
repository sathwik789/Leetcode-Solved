class Solution {
public:
    int divide(int dividend, int divisor) {
        // If both numbers are the same, return 1 directly
        if (dividend == divisor) return 1;
        
        unsigned int ret = 0; // Stores the final quotient
        
        // Determine if the result should be positive or negative
        // If both dividend and divisor have the same sign, the result is positive
        bool isPositive = (0 > dividend == 0 > divisor);
        
        // Convert both dividend and divisor to positive values using abs() 
        // Cast to long long before abs() to avoid overflow (for INT_MIN case)
        unsigned int a = abs((long long)dividend);
        unsigned int b = abs((long long)divisor);

        // Perform bitwise division using exponential subtraction
        while (a >= b) {
            int i = 0;
            
            // Find the largest power of 'b' that fits in 'a' using left shift
            while ((long long)((long long)1 << (i + 1)) * (long long)b < a) {
                i++;
            }
            
            // Add the power of 2 to the result (equivalent to division)
            ret += (1 << i);
            
            // Subtract the corresponding multiple of 'b' from 'a'
            a -= ((long long)1 << i) * (long long)b;
        }

        // Handle edge case where result exceeds INT_MAX
        if (ret == (1 << 31) && isPositive) return INT_MAX;
        
        // Apply the correct sign to the result
        return isPositive ? ret : -ret;
    }
};
