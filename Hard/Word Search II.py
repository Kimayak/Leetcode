
# Given an m x n board of characters and a list of strings words, return all words on the board.

# Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

 

# Example 1:


# Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
# Output: ["eat","oath"]
# Example 2:


# Input: board = [["a","b"],["c","d"]], words = ["abcb"]
# Output: []
 

# Constraints:

# m == board.length
# n == board[i].length
# 1 <= m, n <= 12
# board[i][j] is a lowercase English letter.
# 1 <= words.length <= 3 * 104
# 1 <= words[i].length <= 10
# words[i] consists of lowercase English letters.
# All the strings of words are unique.

# class TrieNode:
#     def __init__(self):
#         self.children = {}
#         self.isWord = False
# class Trie:
#     def __init__(self):
#         self.root = TrieNode()
#     def addWord(self, word:str)->None:
#         node = self.root
#         for char in word:
#             if char not in node.children:
#                 node.children[char] = TrieNode()
#             node = node.children[char]
#         node.isWord = True

# class Solution:
#     def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
#         trie = Trie()

#         for word in words:
#             trie.addWord(word)
#         m = len(board)
#         n = len(board[0])

#         self.result = set()

#         for i in range(m):
#             for j in range(n):
#                 if board[i][j] in trie.root.children:
#                     self.dfs(board, i, j, m, n, trie.root, "")

#         return list(self.result)

#     def dfs(self,  board: List[List[str]], i: int, j: int, m:int, n: int,node: TrieNode(), word: str):
#         if node.isWord: 
#             self.result.add(word)
        
#         if 0<=i<m and 0<=j<n and board[i][j] in node.children:
#             char = board[i][j]
#             board[i][j] = '#'

#             for dx,dy in [(0,1), (1,0), (-1,0), (0,-1)]:
#                 self.dfs(board, i+dx, j+dy, m, n, node.children[char], word+char)
#             board[i][j] = char
class Node:    # about 7x faster due to removal of trie nodes after a target word is found
    def __init__(self):   # itself is the root of the trie
        self.hit = False
        self.next = [None] * 26
        self.cnt = 0

    def idx(self, letter):
        return ord(letter) - ord('a')

    def addWord(self, word):
        curr = self
        for letter in word:
            i = self.idx(letter)
            if not curr.next[i]:
                curr.next[i] = Node()
            curr = curr.next[i]
            curr.cnt += 1
        curr.hit = True

    def removeWord(self, word):
        curr = self
        for letter in word:
            i = self.idx(letter)
            next = curr.next[i]
            next.cnt -= 1
            if next.cnt == 0:
                curr.next[i] = None
                return
            curr = next


class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        root = Node()

        for word in words:
            root.addWord(word)

        m = len(board)
        n = len(board[0])

        visited = [[False] * n for _ in range(m)]
        ans = []

        def dfs(i, j, node, currAns):
            if i < 0 or j < 0 or i >= m or j >= n or visited[i][j]:
                return

            idx = ord(board[i][j]) - ord('a')

            if not node.next[idx]:
                return

            visited[i][j] = True

            nxtNode = node.next[idx]
            nxtWord = currAns + board[i][j]

            if nxtNode.hit:
                ans.append(nxtWord)
                nxtNode.hit = False
                root.removeWord(nxtWord)

            dfs(i + 1, j, nxtNode, nxtWord)
            dfs(i - 1, j, nxtNode, nxtWord)
            dfs(i, j + 1, nxtNode, nxtWord)
            dfs(i, j - 1, nxtNode, nxtWord)

            visited[i][j] = False

        for i in range(m):
            for j in range(n):
                dfs(i, j, root, "")

        return ans