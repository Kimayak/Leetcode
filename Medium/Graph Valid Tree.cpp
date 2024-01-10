

// You have a graph of n nodes labeled from 0 to n - 1. You are given an integer n and a list of edges where edges[i] = [ai, bi] indicates that there is an undirected edge between nodes ai and bi in the graph.

// Return true if the edges of the given graph make up a valid tree, and false otherwise.

 

// Example 1:


// Input: n = 5, edges = [[0,1],[0,2],[0,3],[1,4]]
// Output: true
// Example 2:


// Input: n = 5, edges = [[0,1],[1,2],[2,3],[1,3],[1,4]]
// Output: false
 

// Constraints:

// 1 <= n <= 2000
// 0 <= edges.length <= 5000
// edges[i].length == 2
// 0 <= ai, bi < n
// ai != bi
// There are no self-loops or repeated edges.

class Solution {
public:
    // DFS function to check for cycles and visit all nodes in a connected component
    bool dfs(int node, int parent, vector<int>& visited, vector<vector<int>>& adj) {
        visited[node] = 1; // Mark the current node as visited

        // Iterate through all adjacent nodes
        for (auto n : adj[node]) {
            // If the adjacent node is already visited
            if (visited[n]) {
                // If the visited node is not the parent, it's a cycle
                if (n != parent) return false;
            } else {
                // If the adjacent node is not visited, perform DFS on it
                if (!dfs(n, node, visited, adj)) return false;
            }
        }
        return true; // No cycles found, return true
    }

    // Function to check if the given graph is a valid tree
    bool validTree(int n, vector<vector<int>>& edges) {
        // A tree must have exactly n-1 edges
        if (edges.size() != n - 1) return false;

        // Creating an adjacency list representation of the graph
        vector<vector<int>> adj(n);
        vector<int> visited(n, 0); // Vector to keep track of visited nodes

        // Populate the adjacency list
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // Perform DFS starting from node 0. If it returns false, the graph contains a cycle
        if (!dfs(0, -1, visited, adj)) return false;

        // Check if all nodes are visited (i.e., the graph is connected)
        for (auto v : visited) {
            if (v == 0) return false; // If any node is not visited, return false
        }

        return true; // The graph is a valid tree
    }
};
