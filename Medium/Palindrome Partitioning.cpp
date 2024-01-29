
// Given a string s, partition s such that every 
// substring
//  of the partition is a 
// palindrome
// . Return all possible palindrome partitioning of s.

 

// Example 1:

// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]
// Example 2:

// Input: s = "a"
// Output: [["a"]]
 

// Constraints:

// 1 <= s.length <= 16
// s contains only lowercase English letters.



class Solution {
public:
    vector<vector<string>> partition(string s) {

        vector<vector<string>> result;
        vector<string> currentPartition;

        backtrack(s, 0, currentPartition, result);
        
        return result; 
        
    }

    void backtrack(string& s, int start, vector<string>& currentPartition, vector<vector<string>>& result){

        if(start == s.size()){
            result.push_back(currentPartition);
            return;

        }

        for(int end = start; end<s.size(); end++){
            if(isPalindrome(s,start, end)){
                currentPartition.push_back(s.substr(start, end- start+1));
                backtrack(s, end+1, currentPartition, result);
                currentPartition.pop_back();
            }
        }


    }

    bool isPalindrome(const string& s, int start, int end){
        while(start<end){
            if(s[start++]!= s[end--])
                return false;
        }
        return true;
    }
};