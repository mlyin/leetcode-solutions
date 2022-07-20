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
    bool isLeaf(TreeNode* node) {
        if (node == NULL) {
            return true;
        }
        if (node->left == NULL && node->right == NULL) {
            return true;
        } else {
            return false;
        }
    }
    int minDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        if (isLeaf(root)) {
            return 1;
        } else if ((root->left == NULL && isLeaf(root->right)) || (root->right == NULL && isLeaf(root->left))) {
            return 2;
        } else if ((root->left == NULL) && !isLeaf(root->right)) {
            return 1+(minDepth(root->right));
        } else if  (!isLeaf(root->left) && (root->right == NULL)) {
            return 1+(minDepth(root->left));
        } else {
            return 1+min(minDepth(root->left), minDepth(root->right));
        }
    }
};

int main() {
    Solution sol;

}