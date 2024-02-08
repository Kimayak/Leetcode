
# You have a graph of n nodes. You are given an integer n and an array edges where edges[i] = [ai, bi] indicates that there is an edge between ai and bi in the graph.

# Return the number of connected components in the graph.

 

# Example 1:


# Input: n = 5, edges = [[0,1],[1,2],[3,4]]
# Output: 2
# Example 2:


# Input: n = 5, edges = [[0,1],[1,2],[2,3],[3,4]]
# Output: 1
 

# Constraints:

# 1 <= n <= 2000
# 1 <= edges.length <= 5000
# edges[i].length == 2
# 0 <= ai <= bi < n
# ai != bi
# There are no repeated edges.

class Solution:
    def dfs(self, node: int, visited: List[int], adj:dict ):
        visited[node] = 1

        for neighbor in adj[node]:
            if not visited[neighbor]:
                self.dfs(neighbor, visited, adj)
                
        
    def countComponents(self, n: int, edges: List[List[int]]) -> int:

        adj = {i: [] for i in range(n)}
        visited = [0] * n
        count = 0

        for edge in edges: 
            adj[edge[0]].append(edge[1])
            adj[edge[1]].append(edge[0])

        for i in range(n):
            if( not visited[i]):
                self.dfs(i, visited, adj)
                count+=1
        
        return count 

        
        
            

        

        
        
        