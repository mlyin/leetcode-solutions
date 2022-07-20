#include <bits/stdc++.h>

using namespace std;

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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        findPaths(root, targetSum, vector<int>(), result);
        return result;
    }

    void findPaths(TreeNode* root, int targetSum, vector<int> current, vector<vector<int>> &result) {
        if (root == NULL) {
            return;
        }
        current.push_back(root->val);
        if (root->val == targetSum && root->left == NULL && root->right == NULL) {
            result.push_back(current);
            return;
        }
        findPaths(root->left, targetSum - root->val, current, result);
        findPaths(root->right, targetSum - root->val, current, result);
    }
};

int main() {
    Solution sol;

}   