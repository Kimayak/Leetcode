// Given a square matrix mat, return the sum of the matrix diagonals.

// Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal.

 

// Example 1:


// Input: mat = [[1,2,3],
//               [4,5,6],
//               [7,8,9]]
// Output: 25
// Explanation: Diagonals sum: 1 + 5 + 9 + 3 + 7 = 25
// Notice that element mat[1][1] = 5 is counted only once.
// Example 2:

// Input: mat = [[1,1,1,1],
//               [1,1,1,1],
//               [1,1,1,1],
//               [1,1,1,1]]
// Output: 8
// Example 3:

// Input: mat = [[5]]
// Output: 5
 

// Constraints:

// n == mat.length == mat[i].length
// 1 <= n <= 100
// 1 <= mat[i][j] <= 100



class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        size_t numRows = mat.size();
        size_t numCols = (numRows > 0) ? mat[0].size() : 0;
        int sum = 0;
        for (int i = 0; i <numRows; i++)
        {
            sum = sum+mat[i][i];
            sum = sum+mat[i][numRows-i-1];

        }
        if (numRows%2!=0)
            sum = sum - mat[numRows/2][numRows/2];
        // for(int i = 0; i<numRows; i++)
        // {
        //     if(i!=int(numRows/2) && numRows-i-1!=int(numRows/2))
        //         sum = sum+ mat[i][numRows-i-1];
        // }


    return sum;
        
    }
};