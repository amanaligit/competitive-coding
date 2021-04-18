
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
    TreeNode *newroot;
    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        newroot = root;
        checkNode(root, nullptr, low, high);
        return newroot;
    }

    void checkNode(TreeNode *node, TreeNode *parent, int &low, int &high)
    {
        if (node != nullptr)
        {
            if (node->val < low)
            {
                deleteNode(node, parent, low, high);
                checkNode(node->right, parent, low, high);
                return;
            }
            else if (node->val > high)
            {
                deleteNode(node, parent, low, high);
                checkNode(node->left, parent, low, high);
                return;
            }
            if (parent == nullptr)
            {
                checkNode(node->right, node, low, high);
                checkNode(node->left, node, low, high);
            }
            else
            {
                if (node->val > parent->val)
                {
                    checkNode(node->right, node, low, high);
                }
                if (node->val < parent->val)
                {
                    checkNode(node->left, node, low, high);
                }
            }
        }
    }

    void deleteNode(TreeNode *node, TreeNode *parent, int &low, int &high)
    {

        if (node->val < low)
        {
            if (parent != nullptr)
            {
                if (parent->val < node->val)
                {
                    parent->right = node->right;
                }
                else
                {
                    parent->left = node->right;
                }
            }
            else
            {
                newroot = node->right;
            }
        }

        if (node->val > high)
        {
            if (parent != nullptr)
            {

                if (parent->val < node->val)
                {
                    parent->right = node->left;
                }
                else
                {
                    parent->left = node->left;
                }
            }
            else
            {
                newroot = node->left;
            }
        }
    }

    void insertNode(TreeNode *node, TreeNode *target)
    {
        if (target->left == nullptr)
        {
            target->left = node;
        }
        else
        {
            insertNode(node, target->left);
        }
    }
};