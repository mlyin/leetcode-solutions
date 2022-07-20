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
    long long int result = 0;
    int pathSum(TreeNode* root, int targetSum) {
        if (root) {
            findPaths(root, targetSum);
            pathSum(root->left, targetSum);
            pathSum(root->right, targetSum);
        }
        return result;
    }
    void findPaths(TreeNode* root, long long int targetSum) {
        if (root == NULL) {
            return;
        }
        if (root->val == targetSum) result++;
        findPaths(root->left, targetSum - root->val);
        findPaths(root->right, targetSum - root->val);
    }
};

int main() {
    Solution sol;

}   