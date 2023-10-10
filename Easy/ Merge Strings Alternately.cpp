

// You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

// Return the merged string.

 

// Example 1:

// Input: word1 = "abc", word2 = "pqr"
// Output: "apbqcr"
// Explanation: The merged string will be merged as so:
// word1:  a   b   c
// word2:    p   q   r
// merged: a p b q c r
// Example 2:

// Input: word1 = "ab", word2 = "pqrs"
// Output: "apbqrs"
// Explanation: Notice that as word2 is longer, "rs" is appended to the end.
// word1:  a   b 
// word2:    p   q   r   s
// merged: a p b q   r   s
// Example 3:

// Input: word1 = "abcd", word2 = "pq"
// Output: "apbqcd"
// Explanation: Notice that as word1 is longer, "cd" is appended to the end.
// word1:  a   b   c   d
// word2:    p   q 
// merged: a p b q c   d
 

// Constraints:

// 1 <= word1.length, word2.length <= 100
// word1 and word2 consist of lowercase English letters.


#include <string>
#include <iostream>>
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string out, rem;
       // int merge_length = 0;
        int merge_length = min(word1.size(), word2.size());

        if(size(word1)>size(word2))
        {
            //merge_length = size(word2);
            // cout<<merge_length;
            // cout<<word1.size();
            // cout<<word1.length();
            rem = word1.substr(word2.length());
            // cout<<word1.size() -  merge_length;
            // rem = word1[merge_length : ];
            // cout<<rem;
            
        }
        else if (size(word2)>size(word1))
        {
           // merge_length = size(word1);
            rem = word2.substr(word1.length());
            
        }
        else 
        {
            merge_length = size(word1);
            rem = "";

        }

        for(int i = 0; i < merge_length; i++)
        {
            out = out + word1[i] + word2[i];
        }
        cout<<rem; 
        out = out + rem;
        return out;
    }
};