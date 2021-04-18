int leftChild(int i)
{
    return 2 * i + 1;
}

int rightChild(int i)
{
    return 2 * i + 2;
}
int parent(int i)
{
    if (i <= 0)
        return -1;
    return (i - 1) / 2;
}