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
    bool check(TreeNode* l, TreeNode* r) {
        if (!l && r || l && !r) {
            return false;
        }
        if (!l && !r) {
            return true;
        }
        if (l->val != r->val) {
            return false;
        }
        bool d1 = check(l->left, r->right);
        bool d2 = check(l->right, r->left);
        return d1 && d2;
    }

    bool isSymmetric(TreeNode* root) {
        return check(root->left, root->right);
    }
};