
// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
 

// Example 1:

// Input: s = "()"
// Output: true
// Example 2:

// Input: s = "()[]{}"
// Output: true
// Example 3:

// Input: s = "(]"
// Output: false
 

// Constraints:

// 1 <= s.length <= 104
// s consists of parentheses only '()[]{}'.

class Solution {
public:
    bool isValid(string s) {
        vector<char> emp;

        for(char c:s)
        {
            if(c=='[')
                emp.push_back(c);
            else if(c=='{')
                emp.push_back(c);
            else if(c=='(')
                emp.push_back(c);
            else if ((c==']' || c== '}' || c==')') && emp.size()==0)
                return false;
            else if(c==']' && emp[emp.size()-1]=='[')
            {
                emp.pop_back();            }
            else if(c==']' && emp[emp.size()-1]!='[')
                return false;
            else if(c=='}' && emp[emp.size()-1]=='{')
                emp.pop_back();
            else if(c=='}' && emp[emp.size()-1]!='{')
                return false;
            else if(c==')' && emp[emp.size()-1]=='(')
                emp.pop_back();
            else if(c==')' && emp[emp.size()-1]!='(')
                return false;
         
        }

        if (emp.size()==0)
            return true;
        return false;
        
    }
};