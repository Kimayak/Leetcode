
// Tic-tac-toe is played by two players A and B on a 3 x 3 grid. The rules of Tic-Tac-Toe are:

// Players take turns placing characters into empty squares ' '.
// The first player A always places 'X' characters, while the second player B always places 'O' characters.
// 'X' and 'O' characters are always placed into empty squares, never on filled ones.
// The game ends when there are three of the same (non-empty) character filling any row, column, or diagonal.
// The game also ends if all squares are non-empty.
// No more moves can be played if the game is over.
// Given a 2D integer array moves where moves[i] = [rowi, coli] indicates that the ith move will be played on grid[rowi][coli]. return the winner of the game if it exists (A or B). In case the game ends in a draw return "Draw". If there are still movements to play return "Pending".

// You can assume that moves is valid (i.e., it follows the rules of Tic-Tac-Toe), the grid is initially empty, and A will play first.

 

// Example 1:


// Input: moves = [[0,0],[2,0],[1,1],[2,1],[2,2]]
// Output: "A"
// Explanation: A wins, they always play first.
// Example 2:


// Input: moves = [[0,0],[1,1],[0,1],[0,2],[1,0],[2,0]]
// Output: "B"
// Explanation: B wins.
// Example 3:


// Input: moves = [[0,0],[1,1],[2,0],[1,0],[1,2],[2,1],[0,1],[0,2],[2,2]]
// Output: "Draw"
// Explanation: The game ends in a draw since there are no moves to make.
 

// Constraints:

// 1 <= moves.length <= 9
// moves[i].length == 2
// 0 <= rowi, coli <= 2
// There are no repeated elements on moves.
// moves follow the rules of tic tac toe.



class Solution {
private:
     vector<vector<int>> board;
        int n = 3;
public:
    bool checkRow(int row, int player)
    {
        for(int col = 0; col<n; col++)
            if(board[row][col]!= player)
                return false;
        return true;
    }

    bool checkCol(int col, int player)
    {
        for(int row=0; row<n; row++)
            if(board[row][col]!=player)
                return false;
        return true;
    }

    bool checkDiag(int player)
    {
        for(int rc = 0; rc<n; rc++)
            if(board[rc][rc]!= player)
                return false;
        return true;
    }

    bool checkantidiag(int player)
    {
        for(int row = 0; row<n; row++)
            if(board[row][n-row-1]!= player)
                return false;
        return true;
    }
    string tictactoe(vector<vector<int>>& moves) {
        board.assign(n,vector<int>(n,0));
        int player = 1;
        for(vector<int> move: moves){
            int row = move[0], col =move[1];
            board[row][col] = player;

            if(checkRow(row,player)|| checkCol(col,player)|| (row==col && checkDiag(player))||((row+col ==n-1) && checkantidiag(player)))
                return player==1? "A":"B";
        player*=-1;
        }
       
        return moves.size() == n*n? "Draw": "Pending";
        // vector<vector<int>>& a_moves, b_moves;
        // for(int i = 0; i<size(moves); i = i+2)
        // {
        //     a_moves.push_back(moves[i])
        // }
        // for(int i = 1; i<size(moves); i = i+2)
        // {
        //     b_moves.push_back(moves[i])
        // }

        // for(int j = 0; j<size(a_moves); j++)
        // {
        //     if()
        // }
        // vector<int,int> board;
        // int prev = 1;
        // int win = 1;
        // for(m: moves)
        // {
        //     board[m[0], m[1]] = -1*prev;
        //     prev = -1*prev;
        //     for(int i = 0; i< 3; i++)
        //     {
        //         if(board[i,m[1]] != board[m[0], m[1]])
        //             win = 1;
        //         else
        //             {win = 0;
        //             continue;}
                    
        //     }
        //      for(int j = 0; j< 3; j++)
        //     {
        //         if(board[m[0],j] == board[m[0], m[1]])
        //             win = 1;
        //         else
        //             {win = 0;
        //             continue;}


        //     }
            
        // }
    }
};