long long getSum(vector<int> &BITree, int index)
{
    long long sum = 0; // Iniialize result
    index = index + 1;
    while (index > 0)
    {
        sum += BITree[index];
        index -= index & (-index);
    }
    return sum;
}

void updateBIT(vector<int> &BITree, int n, int index, int val)
{
    index = index + 1;
    while (index <= n)
    {
        BITree[index] += val;
        index += index & (-index);
    }
}

vector<int> constructBITree(vector<int> &arr, int n)
{
    vector<int> BITree(n + 1, 0);
    for (int i = 0; i < n; i++)
        updateBIT(BITree, n, i, arr[i]);
    return BITree;
}

//BITree is a vector of size 1 greater than the original array
