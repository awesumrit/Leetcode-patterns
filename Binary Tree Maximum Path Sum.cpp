/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int sum(TreeNode* root, int &res) {
        if (!root) return 0;
        int lh = sum(root->left, res), rh = sum(root->right, res);
        int max_single = max(max(lh, rh)+root->val, root->val);
        res = max(res, max(max_single, lh+rh+root->val));
        return max_single;
    }
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        sum(root, res);
        return res;
    }
};
