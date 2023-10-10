// You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

// Increment the large integer by one and return the resulting array of digits.

 

// Example 1:

// Input: digits = [1,2,3]
// Output: [1,2,4]
// Explanation: The array represents the integer 123.
// Incrementing by one gives 123 + 1 = 124.
// Thus, the result should be [1,2,4].
// Example 2:

// Input: digits = [4,3,2,1]
// Output: [4,3,2,2]
// Explanation: The array represents the integer 4321.
// Incrementing by one gives 4321 + 1 = 4322.
// Thus, the result should be [4,3,2,2].
// Example 3:

// Input: digits = [9]
// Output: [1,0]
// Explanation: The array represents the integer 9.
// Incrementing by one gives 9 + 1 = 10.
// Thus, the result should be [1,0].


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = size(digits);
        vector<int> result;
        int idx;
        for(int i = 0; i<n; i++)
        {
            idx = n-1-i;
            if(digits[idx]==9)
                digits[idx] = 0;
            else
            {
                digits[idx]+=1;
                return digits;

            }

            
        }
        result.push_back(1);
        result.insert(result.end(), begin(digits), end(digits)); 
        return result;

        //Did not work
        // int d = 0;
        // if(digits[size(digits)-1]+1<9)
        // {
        //    digits[size(digits)-1]= digits[size(digits)-1]+1;
        //    return digits; 
        // }
        
        // for(int i = 0; i<size(digits);i++)
        // {
        //     d += digits[i]*10^(i);

        // }

        // d = d+1;

        // for(int i =0; i < size(digits)+1; i++)
        // {
        //     digits[i] = d/10^i;
        // }

        // return digits;




    }
};