
// Given an array of strings strs, group the anagrams together. You can return the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

// Example 1:

// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
// Example 2:

// Input: strs = [""]
// Output: [[""]]
// Example 3:

// Input: strs = ["a"]
// Output: [["a"]]
 

// Constraints:

// 1 <= strs.length <= 104
// 0 <= strs[i].length <= 100
// strs[i] consists of lowercase English letters.
class Solution {
public:
    // bool isanagram(string s, string t)
    // {
    //     string temp1, temp2;
    //     temp1 = s;
    //     temp2 = t;

    //     sort(temp1.begin(), temp1.end());
    //     sort(temp2.begin(), temp2.end());

    //     return temp1==temp2;

    // }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> temp;
        string sorted;

        for(string str: strs)
        {
            sorted = str;
            sort(sorted.begin(), sorted.end());
            temp[sorted].push_back(str);

            
        }
        for(auto& entry: temp)
        {
            ans.push_back(entry.second);
        }
        return ans;
        // vector<string> temp;
        // for(int i=0; i<strs.size(); i++)
        // {
        //     temp = {};
        //     temp.push_back(strs[i]);
        //     for(int j = i+1; j< strs.size(); ++j)
        //     {
                
        //         if(isanagram(strs[i],strs[j]))

        //             temp.push_back(strs[j]);
                
        //     }
        //     ans.push_back(temp);
        // }
        // return ans;
        
    }
};