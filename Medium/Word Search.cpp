// Given an m x n grid of characters board and a string word, return true if word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

// Example 1:


// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
// Output: true
// Example 2:


// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
// Output: true
// Example 3:


// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
// Output: false
 

// Constraints:

// m == board.length
// n = board[i].length
// 1 <= m, n <= 6
// 1 <= word.length <= 15
// board and word consists of only lowercase and uppercase English letters.
 

// Follow up: Could you use search pruning to make your solution faster with a larger board?

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for(int i = 0 ; i<m; i++){
            for(int j = 0; j<n; j++){
                if(dfs(board,word, 0, i, j))
                    return true;

            }
        }

        return false;
        
    }


    private: 
    bool dfs(vector<vector<char>>& board, const string& word, int index, int x, int y){
        if(index == word.size())
            return true;

       if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != word[index])
            return false; 
        
        char temp = board[x][y];
        board[x][y] = '#';

        bool found = dfs(board, word, index+1, x+1, y)|| dfs(board, word, index+1, x, y+1) || dfs(board, word, index+1, x-1, y)||dfs(board, word, index+1, x, y-1); 

        board[x][y] = temp; 
    return found;
    }

   
};
   