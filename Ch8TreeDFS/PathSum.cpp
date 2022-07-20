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
    int search(TreeNode* root, int currTotal) {
        if (root == NULL) {
            return 0;
        }
        currTotal += root->val;
        if (root->left == NULL && root->right == NULL) {
            return currTotal;
        }
        return (search((root->left), (currTotal*10)) + search((root->right), (currTotal*10)));
    }

    int sumNumbers(TreeNode* root) {
        return search(root, 0);
    }
};

int main() {
    Solution sol;

}   