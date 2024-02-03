

# Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

# An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

# Example 1:

# Input: grid = [
#   ["1","1","1","1","0"],
#   ["1","1","0","1","0"],
#   ["1","1","0","0","0"],
#   ["0","0","0","0","0"]
# ]
# Output: 1
# Example 2:

# Input: grid = [
#   ["1","1","0","0","0"],
#   ["1","1","0","0","0"],
#   ["0","0","1","0","0"],
#   ["0","0","0","1","1"]
# ]
# Output: 3
 

# Constraints:

# m == grid.length
# n == grid[i].length
# 1 <= m, n <= 300
# grid[i][j] is '0' or '1'.


class Solution:
    def dfs(self, grid: List[List[str]], r:int, c:int):
        grid[r][c] = "0"

        if(r-1>=0 and grid[r-1][c] == "1"): 
            self.dfs(grid, r-1, c)
        if(r+1<self.nr and grid[r+1][c] =="1"): 
            self.dfs(grid, r+1, c)
        if(c-1>=0 and grid[r][c-1] == "1"):
            self.dfs(grid, r, c-1)
        if(c+1<self.nc and grid[r][c+1] == "1"): 
            self.dfs(grid, r, c+1)

        

        


    def numIslands(self, grid: List[List[str]]) -> int:
        self.nr = len(grid)
        if not self.nr: return

        self.nc = len(grid[0])
        numIslands = 0
        for r in range(self.nr):
            for c in range(self.nc):
                if(grid[r][c] == "1"):
                    numIslands+=1
                    self.dfs(grid, r, c)
        return numIslands
        