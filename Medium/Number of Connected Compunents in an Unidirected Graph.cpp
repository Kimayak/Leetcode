
// You have a graph of n nodes. You are given an integer n and an array edges where edges[i] = [ai, bi] indicates that there is an edge between ai and bi in the graph.

// Return the number of connected components in the graph.

 

// Example 1:


// Input: n = 5, edges = [[0,1],[1,2],[3,4]]
// Output: 2
// Example 2:


// Input: n = 5, edges = [[0,1],[1,2],[2,3],[3,4]]
// Output: 1
 

// Constraints:

// 1 <= n <= 2000
// 1 <= edges.length <= 5000
// edges[i].length == 2
// 0 <= ai <= bi < n
// ai != bi
// There are no repeated edges.

class Solution {
public:
    void dfs(int node, vector<int>& visited, vector<vector<int>>& adj){
        visited[node] = 1;
        for(auto n: adj[node]){
            if(!visited[n]){
                dfs(n, visited, adj);
            }
        }
      
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> visited(n,0);
        int count =0;

        for(auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        for(int i = 0; i<n; i++){
            if(!visited[i]){
                dfs(i, visited, adj);
                count++;

            }
        }

        return count; 
       
    }
};