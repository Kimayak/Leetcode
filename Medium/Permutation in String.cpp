
// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

// In other words, return true if one of s1's permutations is the substring of s2.

 

// Example 1:

// Input: s1 = "ab", s2 = "eidbaooo"
// Output: true
// Explanation: s2 contains one permutation of s1 ("ba").
// Example 2:

// Input: s1 = "ab", s2 = "eidboaoo"
// Output: false
 

// Constraints:

// 1 <= s1.length, s2.length <= 104
// s1 and s2 consist of lowercase English letters.

class Solution {
private:
bool checkEqual(vector<int>& cnt1, vector<int>& cnt2){
    for(int i=0; i<26; i++){
        if(cnt1[i]!= cnt2[i])
            return false;

    }
    return true; 
    
}
public:
    bool checkInclusion(string s1, string s2) {

        vector<int> cnt1(26, 0), cnt2(26,0);
        int index =0 ; 


        for(int i=0; i<s1.length(); i++){
            index = s1[i]-'a';
            cnt1[index]++;
        }
        int i = 0;
        int windowSize = s1.length();

        while(i<windowSize && i<s2.length()){
            index = s2[i] -'a';
            cnt2[index]++;
            i++;
        }

        if(checkEqual(cnt1,cnt2))
          return 1;
        
        while(i<s2.length()){
            index = s2[i] - 'a';
            cnt2[index]++;

            char oldChar = s2[i-windowSize];
            int index = oldChar - 'a';
            cnt2[index]--;

            i++;
            if(checkEqual(cnt1,cnt2))
               return 1;
        }

        return 0;

     



       
    }
};