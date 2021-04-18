

class Solution
{
public:
    
    unordered_map <TreeNode *, long long> dp;
    int maxProduct(TreeNode *root)
    {
        long long max_pro = 0;
        decideCut(root, 0, max_pro);
        return max_pro%1000000007;
    }

    void decideCut(TreeNode *node, long long parent, long long &max_pro)
    {
        long long left_sum = 0, right_sum = 0;
        if (node->left != nullptr)
            left_sum = sum(node->left);
        if (node->right != nullptr)
            right_sum = sum(node->right);
        if (left_sum == 0 && right_sum == 0)
            return;
        max_pro = std::max(max_pro, std::max((right_sum+parent+node->val)*left_sum, (left_sum+parent+node->val)*right_sum)) ;

        if (left_sum > right_sum)
        {
            decideCut(node->left, parent + node->val + right_sum, max_pro);
        }
         if (right_sum >= left_sum &&node->right!=nullptr)
        {
            decideCut(node->right, parent + node->val + left_sum, max_pro);
        }    
    }

    long long sum(TreeNode *node)
    {
        if(dp[node])
            return dp[node];
        long long left_sum = 0, right_sum = 0;
        if (node->left != nullptr)
            left_sum = sum(node->left);
        if (node->right != nullptr)
            right_sum = sum(node->right);
        dp[node] = left_sum + right_sum + node->val;
        return dp[node];
    }
};