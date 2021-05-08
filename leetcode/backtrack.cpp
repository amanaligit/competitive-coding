bool backtrack(board[M][N], i, j, word, position, visited[M][N])
{
    if (position == word.size() - 1 && board[i][j] == word[position])
        return true;
    else if (board[i][j] != word[position])
        return false;
    else
    {
        visited[i][j] = true;
        //visit right
        ans = false;
        if (j + 1 < board[0].size() && !visited[i][j + 1])
            ans = backtrack(board, i, j + 1, word, position + 1, visited);
        // visit left
        if (j - 1 >= 0 && !visited[i][j - 1] && !ans)
            ans = backtrack(board, i, j - 1, word, position + 1, visited);
        //visit down
        if (i + 1 < board.size() && !visited[i + 1][j] && !ans)
            ans = backtrack(board, i + 1, j, word, position + 1, visited);
        //visit up
        if (i - 1 >= 0 && !visited[i - 1][j] && !ans)
            ans = backtrack(board, i - 1, j, word, position + 1, visited);
        visited[i][j] = false;
        return ans;
    }
}

bool find_solution(board[M][N], word)
{
    //initialize matrix to keep track of what cells have been visited
    visited[M][N];

    for (i = 0; i < M; i++)
        for (j = 0; j < N; j++)
            visited[i][j] = false;

    //loop through all starting positions and check if a solution exits
    for (i = 0; i < board.size(); i++)
        for (j = 0; j < board[0].size(); j++)
            if (backtrack(board, i, j, word, 0, visited))
                return true;

    //return false as no solution exists
    return false;
}