class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        int level = 0;
        vector<vector<int>> levels;
        vector<int> result;
        if (root == NULL) {
            return result;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> level;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left != NULL) {
                    q.push(node->left);
                }
                if (node->right != NULL) {
                    q.push(node->right);
                }
                level.push_back(node->val);
            }
            levels.push_back(level);
        }
        for (auto x : levels) {
            result.push_back(x[x.size() - 1]);
        }
        return result;
    }
};