
// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

 

// Example 1:


// Input: n = 4
// Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
// Example 2:

// Input: n = 1
// Output: [["Q"]]
 

// Constraints:

// 1 <= n <= 9


class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> result; 
        vector<string> board(n, string(n,'.'));

        vector<bool> column(n, false), diag1(2*n-1, false), diag2(2*n-1, false);

        backtrack(0, n , board, result, column, diag1, diag2);
        return result;

        
    }

private: 
    void backtrack(int row, int n, vector<string>& board, vector<vector<string>>& result, vector<bool>& column, vector<bool>& diag1, vector<bool>& diag2){
        if(row == n){
            result.push_back(board);
            return;
        }

        for(int col = 0; col<n; col++){
            if(column[col] || diag1[row+col] || diag2[row-col+n-1]) continue;

            board[row][col] = 'Q';
            column[col] = diag1[row+col] = diag2[row-col+n-1] = true;

            backtrack(row+1, n, board, result, column, diag1, diag2);
            board[row][col] = '.';
            column[col] = diag1[row+col] = diag2[row-col+n-1] = false;


        }
    }
};