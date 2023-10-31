


// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

 

// Example 1:

// Input: x = 2.00000, n = 10
// Output: 1024.00000
// Example 2:

// Input: x = 2.10000, n = 3
// Output: 9.26100
// Example 3:

// Input: x = 2.00000, n = -2
// Output: 0.25000
// Explanation: 2-2 = 1/22 = 1/4 = 0.25
 

// Constraints:

// -100.0 < x < 100.0
// -231 <= n <= 231-1
// n is an integer.
// Either x is not zero or n > 0.
// -104 <= xn <= 104


// The first approach using the binary exponentiation algorithm (exponentiation by squaring) is generally better in terms of time complexity and efficiency compared to the second approach using a simple recursive approach.

// Here's why the first approach is preferred:

// Efficiency: The first approach divides the problem into smaller subproblems by repeatedly squaring x and halving n. This significantly reduces the number of recursive calls, leading to better performance, especially for large values of n. The second approach uses a simple recursive function that has a linear growth in the number of recursive calls, making it less efficient for large n.

// Optimized for Negative Exponents: The first approach is optimized to handle negative exponents efficiently by inverting x once and then proceeding with positive exponents, whereas the second approach uses the pow function to calculate the result for negative exponents. The pow function may involve additional computation and rounding errors.

// Clarity and Maintainability: The first approach is a well-known and standard algorithm for exponentiation, making the code more understandable for others who read it. It's a well-established algorithm and is commonly used for its efficiency and correctness.

// For these reasons, the first approach is generally considered better for calculating x to the power of n. It's more efficient, optimized for negative exponents, and provides a clearer and more maintainable solution.
class Solution {
public:
    long double myPow(long double x, long long n) {
        if (n == 0)
            return 1.0;
        if (n<0)
            return 1.0/pow(x, -n);
        if(n%2 == 1)
            return x*myPow(x*x,(n-1)/2);
        else 
            return myPow(x*x, n/2);
        
    }
};

// class Solution {
// public:
//     long double myPow(long double x, long long n) {
//         if (n == 0)
//             return 1.0;
//         if (n<0)
//             return 1.0/pow(x, -n);
//         return x*myPow(x, n-1);
//         // if(n%2 == 1)
//         //     return x*myPow(x*x,(n-1)/2);
//         // else 
//         //     return myPow(x*x, n/2);
        
//     }
// };
