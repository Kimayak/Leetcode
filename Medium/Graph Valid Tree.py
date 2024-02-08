

# You have a graph of n nodes labeled from 0 to n - 1. You are given an integer n and a list of edges where edges[i] = [ai, bi] indicates that there is an undirected edge between nodes ai and bi in the graph.

# Return true if the edges of the given graph make up a valid tree, and false otherwise.

 

# Example 1:


# Input: n = 5, edges = [[0,1],[0,2],[0,3],[1,4]]
# Output: true
# Example 2:


# Input: n = 5, edges = [[0,1],[1,2],[2,3],[1,3],[1,4]]
# Output: false
 

# Constraints:

# 1 <= n <= 2000
# 0 <= edges.length <= 5000
# edges[i].length == 2
# 0 <= ai, bi < n
# ai != bi
# There are no self-loops or repeated edges.


class Solution:
    def dfs(self, node:int, parent:int, visited: List[int], adj: dict ) -> bool:
        visited[node] = 1

        for neighbor in adj[node]:
            if(visited[neighbor]):
                if neighbor!= parent : return False

            else:
                if not self.dfs(neighbor, node, visited, adj): return False
        return True
                

        
        

    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        if(len(edges)!= n-1): return False

        adj = {i:[] for i in range(n)}
        visited = [0]*n

        for edge in edges: 
            adj[edge[0]].append(edge[1])
            adj[edge[1]].append(edge[0])

        if( not self.dfs(0,-1, visited, adj)): return False

        for v in visited:
            if v==0:
                return False
        return all(visited)

        
        
        

        


        
        