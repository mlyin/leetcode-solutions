#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int result = INT_MIN;
    int maxPathSum(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        if (root) {
            result = max(max(result, root->val), root->val + findMaxIncluding(root->left) + findMaxIncluding(root->right));
            maxPathSum(root->left);
            maxPathSum(root->right);
        }
        return result;
    }
    int findMaxIncluding(TreeNode* root) {
        int curr_max = 0;
        if (root == NULL) {
            return 0;
        }
        if (root->left == NULL && root->right == NULL) {
            return max(curr_max, root->val);
        }
        if (root->left == NULL && root->right != NULL) {
            return max(curr_max, root->val + findMaxIncluding(root->right));
        }
        if (root->left != NULL && root->right == NULL) {
            return max(curr_max, root->val + findMaxIncluding(root->left));
        }
        return max(curr_max, root->val+max(findMaxIncluding(root->left), findMaxIncluding(root->right)));
    }
};

int main() {
    Solution sol;

}   