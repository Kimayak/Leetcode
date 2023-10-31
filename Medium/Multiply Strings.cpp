
// Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

// Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

 

// Example 1:

// Input: num1 = "2", num2 = "3"
// Output: "6"
// Example 2:

// Input: num1 = "123", num2 = "456"
// Output: "56088"
 

// Constraints:

// 1 <= num1.length, num2.length <= 200
// num1 and num2 consist of digits only.
// Both num1 and num2 do not contain any leading zero, except the number 0 itself.


class Solution {
public:
    // int strtoint(string num)
    // {
    //     int res = 0;
 
    // // Traversing string
    // for (char c : num) {
    //     // Checking if the element is number
    //     if (c >= '0' && c <= '9') {
    //         res = res * 10 + (c - '0');
    //     }
    //     // Otherwise print bad output
    //     else {
    //         cout << "Bad Input";
    //         return -1;
    //     }
    // }
 
    // //cout << res;
    // return res;
    // }
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0")
            return "0";

        vector<int> ans(num1.size()+num2.size(), 0);
        //int sum = 0;

        for(int i = num1.size()-1; i>=0; i--)
        {
            for(int j = num2.size()-1; j>=0; j--)
            {
                ans[i+j+1]+=((num1[i]-'0')*(num2[j]-'0'));
                ans[i+j]+=ans[i+j+1]/10;
                ans[i+j+1]%=10;
            }

        }
        
        int i = 0;
        while(i<ans.size() && ans[i]==0)
            ++i;
        string res="";
        while(i<ans.size())
            res+=to_string(ans[i++]);
        
        return res;

        // int n1 = strtoint(num1);
        // int n2 = strtoint(num2);
        // //cout<<n1<<n2;
        // int temp;


        // int sum = n1*n2;
        // if(n1 == 0 || n2 == 0)
        //     return "0";
        
        // //cout<< sum; 
        // string ans;
        // while (sum > 0)
        // {
        //     temp = sum%10 ;
        //     cout<< temp;
        //     ans+=to_string(temp);
        //     sum = sum/10;

        // }
        // reverse(ans.begin(), ans.end());
        // //reverse ans;
        // return ans;
       // return "1";
        
    }
};