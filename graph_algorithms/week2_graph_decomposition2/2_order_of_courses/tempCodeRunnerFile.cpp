if(!marked[i])
    {
        if(!deleted[i])
        {
            reach(adj, i, deleted, marked, output);
        }
    }