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
    int num(TreeNode* root) {
        if(root == NULL) return 0;

        return num(root->left) + 1 + num(root->right); 
    }
    int sum(TreeNode* root) {
        if(root == NULL) return 0;

        return sum(root->left) + root->val + sum(root->right);
    }
    int averageOfSubtree(TreeNode* root) {
        if(root == NULL) return 0;

        int ans = averageOfSubtree(root->left) + averageOfSubtree(root->right);
        if(sum(root) / num(root) == root->val) ans += 1;
        return ans;
    }
};
