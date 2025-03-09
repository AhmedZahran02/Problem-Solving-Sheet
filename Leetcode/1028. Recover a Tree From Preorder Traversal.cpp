class Solution
{
public:
    TreeNode *recoverFromPreorder(string traversal)
    {
        stack<pair<TreeNode *, int>> st;
        int i = 0, n = traversal.size();

        while (i < n)
        {
            int depth = 0;
            while (i < n && traversal[i] == '-')
            {
                depth++;
                i++;
            }

            int num = 0;
            while (i < n && isdigit(traversal[i]))
            {
                num = num * 10 + (traversal[i] - '0');
                i++;
            }

            TreeNode *node = new TreeNode(num);

            while (!st.empty() && st.top().second >= depth)
            {
                st.pop();
            }

            if (!st.empty())
            {
                if (!st.top().first->left)
                    st.top().first->left = node;
                else
                    st.top().first->right = node;
            }

            st.push({node, depth});
        }

        while (st.size() > 1)
            st.pop();
        return st.top().first;
    }
};
