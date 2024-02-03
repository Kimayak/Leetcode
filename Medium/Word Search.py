

# Given an m x n grid of characters board and a string word, return true if word exists in the grid.

# The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

# Example 1:


# Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
# Output: true
# Example 2:


# Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
# Output: true
# Example 3:


# Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
# Output: false
 

# Constraints:

# m == board.length
# n = board[i].length
# 1 <= m, n <= 6
# 1 <= word.length <= 15
# board and word consists of only lowercase and uppercase English letters.
 

# Follow up: Could you use search pruning to make your solution faster with a larger board?
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        self.m = len(board)
        self.n = len(board[0])

        for i in range(self.m):
            for j in range(self.n):
                if(self.dfs(board, word, 0, i, j)):
                    return True
        return False
    
    def dfs(self,board: List[List[str]], word: str, index: int, x: int, y:int ) ->bool:
        if(index == len(word)): return True

        if(x<0 or x>=self.m or y<0 or y>=self.n or word[index]!=board[x][y] ): return False

        temp = board[x][y]

        board[x][y] = "#"

        found = self.dfs(board, word, index+1, x+1, y) or self.dfs(board, word, index+1, x-1, y) or self.dfs(board, word, index+1, x, y+1) or self.dfs(board, word, index+1, x, y-1) 

        board[x][y] = temp

        return found

    
        