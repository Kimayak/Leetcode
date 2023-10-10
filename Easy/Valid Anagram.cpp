// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

// Example 1:

// Input: s = "anagram", t = "nagaram"
// Output: true
// Example 2:

// Input: s = "rat", t = "car"
// Output: false
 

// Constraints:

// 1 <= s.length, t.length <= 5 * 104
// s and t consist of lowercase English letters.

// Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?



class Solution {
public:
    bool isAnagram(string s, string t) {

        if(size(s)!=size(t))
            return 0;
        //string temp; 
        
       //string temp1, temp2;
       sort(s.begin(), s.end()); 
       sort(t.begin(), t.end());
       return s==t;
        // int s1,t1;
        // char diff;
        // s1 = t1 = 0;
        // for(int i = 0; i<s.size(); i++)
        // {
        //     s1 = s1 + int(s[i]);
        // }
        
        //  for(int i = 0; i<t.size(); i++)
        // {
        //     t1 = t1 + int(t[i]);
        // }

        // diff = t1-s1;

        // if (diff == 0)
        //     return 1;
        // else 
        //     return 0;
        // bool temp = 1;
        // cout<<size(s);
        // cout<<size(t);
        // if(size(s)!=size(t))
        //     return 0;
        // for(int i=0;i<size(s); i++)
        // {
        
        // for(int j=0;j<size(t);j++)
        // {
        // if (s[i]== t[j])
        //     {temp = 1;
        //     cout<<s[i];
        //     cout<<t[j];
        //     cout<<temp;
        //     break;}
        // else 

        //     {temp = 0;
        //     cout<<"Enter?? ";
        //     }
        // }
        
        // }

        // if (temp == 0 )
        //     return 0;
        // return 1;
        
    }
};