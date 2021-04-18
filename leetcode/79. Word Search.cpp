#include <bits/stdc++.h>

using namespace std;
//=======================

class Solution
{
public:
    bool findstring(vector<vector<char>> &board, int i, int j, string word, int ptr, int pi, int pj, vector<vector<bool>> &visited)
    {
        if (ptr == word.size() - 1 && board[i][j] == word[ptr])
            return true;
        else if (board[i][j] != word[ptr])
            return false;
        else
        {
            visited[i][j] = true;
            //visit right
            bool ans = false;
            if (pj != j + 1 && j + 1 < (int)board[0].size() && !visited[i][j + 1])
                ans = findstring(board, i, j + 1, word, ptr + 1, i, j, visited);
            // visit left
            if (pj != j - 1 && j - 1 >= 0 && !visited[i][j - 1] && !ans)
                ans = findstring(board, i, j - 1, word, ptr + 1, i, j, visited);
            //visit down
            if (pi != i + 1 && i + 1 < (int)board.size() && !visited[i + 1][j] && !ans)
                ans = findstring(board, i + 1, j, word, ptr + 1, i, j, visited);
            //visit up
            if (pi != i - 1 && i - 1 >= 0 && !visited[i - 1][j] && !ans)
                ans = findstring(board, i - 1, j, word, ptr + 1, i, j, visited);
            visited[i][j] = false;
            return ans;
        }
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        bool ans = false;
        for (int i = 0; i < (int)board.size(); i++)
        {
            for (int j = 0; j < (int)board[0].size(); j++)
            {
                if (board[i][j] == word[0])
                {
                    if (findstring(board, i, j, word, 0, -1, -1, visited))
                    {
                        ans = true;
                    }
                }
            }
        }
        return ans;
    }
};