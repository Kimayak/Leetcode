
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

// Example 1:

// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]
// Example 2:

// Input: n = 1
// Output: ["()"]
 

// Constraints:

// 1 <= n <= 8

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;

        generate(result, "", n, 0, 0);
        return result;

        
        
    }

    void generate(vector<string>& result, string current, int n, int open, int close){
        if(current.length() == n*2){
            result.push_back(current);
            return; 
        }
        if(open<n){
            generate(result, current+ "(", n, open+1, close);
        }
        if(close<open){
            generate(result, current+ ")", n, open, close+1);
        }

    }
};