// @before-stub-for-debug-begin
#include <vector>
#include <string>
using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 *
 * https://leetcode.com/problems/sudoku-solver/description/
 *
 * algorithms
 * Hard (47.20%)
 * Likes:    2701
 * Dislikes: 104
 * Total Accepted:    233.7K
 * Total Submissions: 495.1K
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 * 
 * A sudoku solution must satisfy all of the following rules:
 * 
 * 
 * Each of the digits 1-9 must occur exactly once in each row.
 * Each of the digits 1-9 must occur exactly once in each column.
 * Each of the digits 1-9 must occur exactly once in each of the 9 3x3
 * sub-boxes of the grid.
 * 
 * 
 * The '.' character indicates empty cells.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: board =
 * [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
 * Output:
 * [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
 * Explanation: The input board is shown above and the only valid solution is
 * shown below:
 * 
 * 
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * board.length == 9
 * board[i].length == 9
 * board[i][j] is a digit or '.'.
 * It is guaranteed that the input board has only one solution.
 * 
 * 
 */

// @lc code=start

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<unordered_set<char>> cols;
    vector<unordered_set<char>> rows;
    vector<vector<unordered_set<char>>> boxes;
    vector<vector<char>> sboard;

    bool validAndInsert(int i, int j, char val)
    {
        //check cols
        if (cols[j].find(val) != cols[j].end())
            return false;

        //check row
        if (rows[i].find(val) != rows[i].end())
            return false;

        //check box;
        int bi = i / 3;
        int bj = j / 3;
        if (boxes[bi][bj].find(val) != boxes[bi][bj].end())
            return false;

        //everything fine, insert  val
        cols[j].insert(val);
        rows[i].insert(val);
        boxes[bi][bj].insert(val);
        sboard[i][j] = val;
        return true;
    }

    void deleteVal(int i, int j, char val)
    {
        int bi = i / 3;
        int bj = j / 3;
        cols[j].erase(val);
        rows[i].erase(val);
        boxes[bi][bj].erase(val);
        sboard[i][j] = '.';
    }

    bool nextCall(int i, int j)
    {
        int nj = j == sboard[0].size() - 1 ? 0 : j + 1;
        int ni = j == sboard[0].size() - 1 ? i + 1 : i;
        return solver(ni, nj);
    }

    bool solver(int i, int j)
    {
        if (i == sboard.size())
            return true;
        if (sboard[i][j] != '.')
            return nextCall(i, j);
        for (char val = '1'; val <= '9'; val++)
        {
            if (validAndInsert(i, j, val))
            {
                //move ahead
                if (nextCall(i, j))
                    return true;
                //delete entries
                deleteVal(i, j, val);
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        cols.resize(9);
        rows.resize(9);
        boxes.resize(3, vector<unordered_set<char>>(3));
        sboard.resize(board.size(), vector<char>(board[0].size()));
        for (size_t i = 0; i < board.size(); i++)
        {
            for (size_t j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] != '.')
                    validAndInsert(i, j, board[i][j]);
                sboard[i][j] = board[i][j];
            }
        }
        solver(0, 0);
        for (size_t i = 0; i < board.size(); i++)
            for (size_t j = 0; j < board[0].size(); j++)
                board[i][j] = sboard[i][j];
    }
};

// @lc code=end
