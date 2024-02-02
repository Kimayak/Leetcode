
// In this problem, a tree is an undirected graph that is connected and has no cycles.

// You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

// Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

 

// Example 1:


// Input: edges = [[1,2],[1,3],[2,3]]
// Output: [2,3]
// Example 2:


// Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
// Output: [1,4]
 

// Constraints:

// n == edges.length
// 3 <= n <= 1000
// edges[i].length == 2
// 1 <= ai < bi <= edges.length
// ai != bi
// There are no repeated edges.
// The given graph is connected.

class UnionFind{
    public:
    vector<int> parent;
    UnionFind(int size): parent(size+1){
        for(int i =0; i<=size; i++){
            parent[i] = i;
        }
    }

    int find(int x){
        if(x!=parent[x]){
            parent[x] = find(parent[x]);

        }
        return parent[x];
    }

    bool unite(int x, int y){
        int rootX = find(x);
        int rootY = find(y);
        if(rootX == rootY) return false;
        parent[rootX] = rootY;
        return true;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        UnionFind uf(edges.size());
        for (auto& edge: edges){
            if(!uf.unite(edge[0], edge[1]))
            {
                return edge;
            }

        }
        return {};
    }
};