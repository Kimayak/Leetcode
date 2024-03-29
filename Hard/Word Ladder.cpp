
// A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

// Every adjacent pair of words differs by a single letter.
// Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
// sk == endWord
// Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

 

// Example 1:

// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
// Output: 5
// Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
// Example 2:

// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
// Output: 0
// Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
 

// Constraints:

// 1 <= beginWord.length <= 10
// endWord.length == beginWord.length
// 1 <= wordList.length <= 5000
// wordList[i].length == beginWord.length
// beginWord, endWord, and wordList[i] consist of lowercase English letters.
// beginWord != endWord
// All the words in wordList are unique.


class Solution {
public:
    bool canTransform(const string& s1, const string& s2){
        int diffcount =0 ;
        for(int i = 0; i < s1.size(); i++){
            if (s1[i]!=s2[i]){
                if(++diffcount>1) return false;

            }
            


        }
        return diffcount == 1;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> dict(wordList.begin(), wordList.end());

        if (dict.find(endWord) == dict.end()) return 0;

        queue<string> q;
        q.push(beginWord);

        int level = 1;

        while(!q.empty()){
            int size = q.size();
            for(int i =0; i<size; i++){
                string currentWord = q.front();
                q.pop();

                if(currentWord == endWord) return level;
                for(int j = 0; j<currentWord.length(); j++){
                    string temp = currentWord;
                    for ( char c = 'a'; c<='z'; c++ ){
                        temp[j] = c;
                        if(dict.find(temp)!= dict.end() && temp!= currentWord){
                            q.push(temp);
                            dict.erase(temp);
                        }
                    }
                }
            }
            ++level;
        }
        return 0; 
        
    }
};