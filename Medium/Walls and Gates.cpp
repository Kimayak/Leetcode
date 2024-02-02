// <!-- 
// You are given an m x n grid rooms initialized with these three possible values.

// -1 A wall or an obstacle.
// 0 A gate.
// INF Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
// Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

 

// Example 1:


// Input: rooms = [[2147483647,-1,0,2147483647],[2147483647,2147483647,2147483647,-1],[2147483647,-1,2147483647,-1],[0,-1,2147483647,2147483647]]
// Output: [[3,-1,0,1],[2,2,1,-1],[1,-1,2,-1],[0,-1,3,4]]
// Example 2:

// Input: rooms = [[-1]]
// Output: [[-1]]
 

// Constraints:

// m == rooms.length
// n == rooms[i].length
// 1 <= m, n <= 250
// rooms[i][j] is -1, 0, or 231 - 1. --> -->

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if(rooms.empty()) return;

        int m = rooms.size(), n = rooms[0].size();

        queue<pair<int,int>> q;
        const int INF = 2147483647;

        vector<pair<int,int>> directions = {{-1,0},{0,-1},{1,0},{0,1}};

        for(int i =0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(rooms[i][j]==0) //gate
                    q.push({i,j});
            }
        }

        while(!q.empty()){
            auto [x,y] = q.front();

            q.pop();
            for(auto& [dx,dy]: directions){
                int nx = x+dx, ny = y+dy;

                if(nx>=0 && nx<m && ny>=0 && ny<n && rooms[nx][ny] == INF){
                    rooms[nx][ny] = rooms[x][y] + 1;
                    q.push({nx,ny});
                }
            }

        }
        
    }
};