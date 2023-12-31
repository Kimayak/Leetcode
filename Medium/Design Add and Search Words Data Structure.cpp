
// Design a data structure that supports adding new words and finding if a string matches any previously added string.

// Implement the WordDictionary class:

// WordDictionary() Initializes the object.
// void addWord(word) Adds word to the data structure, it can be matched later.
// bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
 

// Example:

// Input
// ["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
// [[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
// Output
// [null,null,null,null,false,true,true,true]

// Explanation
// WordDictionary wordDictionary = new WordDictionary();
// wordDictionary.addWord("bad");
// wordDictionary.addWord("dad");
// wordDictionary.addWord("mad");
// wordDictionary.search("pad"); // return False
// wordDictionary.search("bad"); // return True
// wordDictionary.search(".ad"); // return True
// wordDictionary.search("b.."); // return True
 

// Constraints:

// 1 <= word.length <= 25
// word in addWord consists of lowercase English letters.
// word in search consist of '.' or lowercase English letters.
// There will be at most 2 dots in word for search queries.
// At most 104 calls will be made to addWord and search.


class TrieNode{
    public:
    unordered_map<char, TrieNode*> children;
    bool isWord; 

    TrieNode(){
        isWord = false; 
    }
};


class WordDictionary {
private: 
TrieNode* root; 
public:
    WordDictionary() {
        root = new TrieNode();         
    }
    
    void addWord(string word) {
        TrieNode* node = root; 

        for(int i = 0; i<word.length(); i++){
            char c = word[i];

            if(node->children.find(c)== node->children.end()){
                // condition: did not find c, then create new node
                node->children[c] = new TrieNode(); 
            }
            node = node->children[c]; // changing current node specific child node! 
        }
        node->isWord = true; // at the end of the word we change bool var
       
        
    }
    
    bool search(string word) {
        return searchHelper(root, word, 0);//iterative search function
        
        
    }
    bool searchHelper(TrieNode* node, string& word, int index){
        //checks if index has reached end of the word, if yes then it returns the bool char
        if (index==word.length()){
            return node->isWord;
        }
        
        char c = word[index];
        if (c == '.'){
            //auto& p: This is a reference to a key-value pair in the node->children map. Here, p.first is the character, and p.second is the corresponding child node.
            for (auto& p: node->children){
                if(searchHelper(p.second, word, index+1))
                    return true;
            }
            return false;
        }
        else{
            if(node->children.find(c) == node->children.end()){
                //did not find c
                return false;
            }
            //recursively goes through child nodes corresponding to each character
            TrieNode* child = node->children[c]; 
            return searchHelper(child, word, index+1); 
        }
       
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */