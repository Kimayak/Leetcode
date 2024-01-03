
// Given an m x n matrix, return all elements of the matrix in spiral order.

 

// Example 1:


// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]
// Example 2:


// Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 10
// -100 <= matrix[i][j] <= 100

class Solution {
public:
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        vector<int> ans;

        if(row == 0)
            return ans;

        vector<vector<bool>>seen(row,vector<bool>(col,false));

        int dr[] = {0,1,0,-1};
        int dc[] = {1,0,-1,0};
        int x=0, y=0,di=0;

        for(int i =0; i<row*col; i++){
            ans.push_back(matrix[x][y]);
            
            seen[x][y] = true;

            int newX = x + dr[di];
            int newY = y+ dc[di];

            if(0<=newX && newX<row && 0<=newY && newY<col && !seen[newX][newY]){
                x = newX;
                y = newY;
            }
            else{
                di = (di+1) %4;
                x+=dr[di];
                y+=dc[di];
            }





        }

        return ans; 




        
    }
};