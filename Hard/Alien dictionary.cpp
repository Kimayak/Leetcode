
// There is a new alien language that uses the English alphabet. However, the order of the letters is unknown to you.

// You are given a list of strings words from the alien language's dictionary. Now it is claimed that the strings in words are 
// sorted lexicographically
//  by the rules of this new language.

// If this claim is incorrect, and the given arrangement of string in words cannot correspond to any order of letters, return "".

// Otherwise, return a string of the unique letters in the new alien language sorted in lexicographically increasing order by the new language's rules. If there are multiple solutions, return any of them.

 

// Example 1:

// Input: words = ["wrt","wrf","er","ett","rftt"]
// Output: "wertf"
// Example 2:

// Input: words = ["z","x"]
// Output: "zx"
// Example 3:

// Input: words = ["z","x","z"]
// Output: ""
// Explanation: The order is invalid, so return "".
 

// Constraints:

// 1 <= words.length <= 100
// 1 <= words[i].length <= 100
// words[i] consists of only lowercase English letters.

class Solution {
public:
    string alienOrder(vector<string>& words) {

        unordered_map<char, unordered_set<char>> adj;

        unordered_map<char, int> degree;
        string result;

        for(string word: words){
            for(char c: word){
                degree[c] = 0;
            }
        }

        for(int i=0; i<words.size()-1; i++){
            string word1 = words[i];
            string word2 = words[i+1];

            bool found = false;

            for(int j = 0; j<min(word1.length(), word2.length()); j++){
                char parent = word1[j], child = word2[j];
                if(parent!= child){
                    if(!adj[parent].count(child)){
                        adj[parent].insert(child);
                        degree[child]++;
                    }
                    found = true;
                    break;
                }
            }

            if(!found && word1.length()> word2.length()) return "";


        }

        vector<char> queue;
        for(auto& p: degree){
            if(p.second == 0) queue.push_back(p.first);
        }

        while(!queue.empty()){
            char c = queue.back();
            queue.pop_back();
            result+=c;

            for(char next: adj[c]){
                if(--degree[next] == 0) queue.push_back(next);
            }
        }
        return result.length() == degree.size()? result : "";
    }
};