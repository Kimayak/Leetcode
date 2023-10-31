
// Given two binary strings a and b, return their sum as a binary string.

 

// Example 1:

// Input: a = "11", b = "1"
// Output: "100"
// Example 2:

// Input: a = "1010", b = "1011"
// Output: "10101"
 

// Constraints:

// 1 <= a.length, b.length <= 104
// a and b consist only of '0' or '1' characters.
// Each string does not contain leading zeros except for the zero itself.

#include<bits/stdc++.h>
class Solution {
public:
//int not able to store hugee binary numbers
//     string toBinary(int n) {
//         if (n==0) return "0";
//         else if (n==1) return "1";
//         else if (n%2 == 0) return toBinary(n/2) + "0";
//         else if (n%2 != 0) return toBinary(n/2) + "1";
//         return 0; 
//     }
//   int binaryToDecimal(string n) 
// { 
//     string num = n; 
//     double dec_value = 0; 
  
//     // Initializing base value to 1, i.e 2^0 
//     double base = 1; 
  
//     int len = num.length(); 
//     for (int i = len - 1; i >= 0; i--) { 
//         if (num[i] == '1') 
//             dec_value += base; 
//         base = base * 2; 
//     } 
  
//     return dec_value; 
// } 

    string addBinary(string a, string b) {
        string res; 
        if (a.size()>b.size())
            return addBinary(b,a);
        
        int diff = b.length() - a.length();
        string padding;
        for (int i = 0; i < diff; i++)
                 padding.push_back('0');
        a =  padding + a;
        char carry = '0';
        for (int i = a.length() - 1; i >= 0; i--) {
        // This if condition solves 110 111 possible cases
            if (a[i] == '1' && b[i] == '1') {
                if (carry == '1')
                    res.push_back('1'), carry = '1';
                else
                    res.push_back('0'), carry = '1';
            }
            // This if condition solves 000 001 possible cases
            else if (a[i] == '0' && b[i] == '0') {
                if (carry == '1')
                    res.push_back('1'), carry = '0';
                else
                    res.push_back('0'), carry = '0';
            }
            // This if condition solves 100 101 010 011 possible
            // cases
            else if (a[i] != b[i]) {
                if (carry == '1')
                    res.push_back('0'), carry = '1';
                else
                    res.push_back('1'), carry = '0';
            }
        }
    
    // If at the end there is carry then just add it to the
        // result
        if (carry == '1')
            res.push_back(carry);
        // reverse the result
        reverse(res.begin(), res.end());
    
        // To remove leading zeroes
        int index = 0;
        while (index + 1 < res.length() && res[index] == '0')
            index++;
        return (res.substr(index));



        
        // double a1 =binaryToDecimal(a);
        // double  b1 =binaryToDecimal(b);

        // double sum1 = a1+b1;
        // string res;
        // res = toBinary(sum1);
        // return res; 

        
    }
};