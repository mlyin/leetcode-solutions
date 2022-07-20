#include <bits/stdc++.h>

using namespace std;


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
    int globalMax = 0;  
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        } else if (root->left == NULL && root->right == NULL) {
            return 0;
        } else {
            int lDepth = maxDepth(root->left);
            int rDepth = maxDepth(root->right);
            if (lDepth > rDepth) {
                return lDepth + 1;
            } else {
                return rDepth + 1;
            }
        }
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        if (root->left == NULL && root->right == NULL) {
            return 0;
        }
        if (root->left == NULL && root->right != NULL) {
            return 1+maxDepth(root->right);
        } else if (root->left != NULL && root->right == NULL) {
            return 1+maxDepth(root->left);
        }
        int currMax = 2+(maxDepth(root->left) + maxDepth(root->right));
        globalMax = max(max(currMax, globalMax), max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
        return globalMax;
    }
};

int main() {
    Solution sol;

}   