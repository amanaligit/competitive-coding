#include <iostream>
#include <vector>
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
    class Solution
    {
    public:
        bool isValidBST(TreeNode *root)
        {
            std::vector<int> v;
            inOrderTraversal(root, v);
            std::vector<int> temp = v;
            sort(v.begin(), v.end());
            if(v.size()>=1)
            {

            }
           
            
            if(v==temp)
                return true;
            return false;
            
        }

        void inOrderTraversal(TreeNode *root, std::vector<int> &v)
        {
            if (root->left != nullptr)
                inOrderTraversal(root->left, v);
            v.push_back(root->val);
            if (root->right != nullptr)
                inOrderTraversal(root->right, v);
        }
    };