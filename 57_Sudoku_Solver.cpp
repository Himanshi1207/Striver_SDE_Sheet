// TC-exponential
// SC-Auxiliary Stack Space
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isSafe(char ch, vector<vector<char>> &board, int row, int col)
    {
        for (int i = 0; i < board.size(); i++)
        {
            if (board[i][col] == ch)
                return false;
            if (board[row][i] == ch)
                return false;
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == ch)
                return false;
        }
        return true;
    }
    bool solve(vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board.size(); j++)
            {
                if (board[i][j] == '.')
                {
                    for (char k = '1'; k <= '9'; k++)
                    {
                        if (isSafe(k, board, i, j))
                        {
                            board[i][j] = k;
                            if (solve(board) == true)
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }
};