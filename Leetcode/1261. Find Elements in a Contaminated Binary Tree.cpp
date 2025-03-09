// Made by AOZPROGRAMMING - All Rights Reserved :)
class FindElements
{
private:
    map<int, bool> mp;
    TreeNode *root;

    void traverse(TreeNode *node, int id)
    {
        if (!node)
            return;
        mp[id] = 1;
        traverse(node->left, 2 * id + 1);
        traverse(node->right, 2 * id + 2);
    }

public:
    FindElements(TreeNode *root)
    {
        root = root;
        traverse(root, 0);
    }

    bool find(int target)
    {
        return mp[target];
    }
};