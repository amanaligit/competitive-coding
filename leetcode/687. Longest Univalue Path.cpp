#include <unordered_map>
using namespace std;
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int longestUnivaluePath(TreeNode *root)
    {
        int max_len = 0;
        if (root != nullptr)
            traverse(root, max_len);
        return max_len;
    }
    
    void traverse(TreeNode *root, int &max_len)
    {
        max_len = std::max(max_len, maxCalc(root));`
        if (root->left != nullptr)
            traverse(root->left, max_len);
        if (root->right != nullptr)
            traverse(root->right, max_len);
    }

    int maxCalc(TreeNode *root)
    {
        int leftans = 0;
        int rightans = 0;
        if (root->left != nullptr)
        {
            if (root->left->val == root->val)
                leftans = 1 + treeHeight(root->left);
        }
        if (root->right != nullptr)
        {
            if (root->right->val == root->val)
                rightans = 1 + treeHeight(root->right);
        }
        return leftans + rightans;
    }

    int treeHeight(TreeNode *node)
    {
        int leftHeight = 0, rightHeight = 0;
        if (node->left != nullptr)
        {
            if (node->left->val == node->val)
            {
                leftHeight = 1 + treeHeight(node->left);
            }
        }
        if (node->right != nullptr)
        {
            if (node->right->val == node->val)
            {
                rightHeight = 1 + treeHeight(node->right);
            }
        }
        return std::max(leftHeight, rightHeight);
    }
};