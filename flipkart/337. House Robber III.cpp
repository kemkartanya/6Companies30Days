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
    map<pair<TreeNode*, int>, int> mp;
    int solve(TreeNode* root, int prev) {
        if(root == NULL) return 0; 

        pair<TreeNode*, int> p = {root, prev};
        if(mp.find(p) != mp.end()) return mp[p];

        if(prev == 1) 
            return mp[p] = solve(root->left, 0) + solve(root->right, 0);
        else 
            return mp[p] = max(solve(root->left, 1) + root->val + solve(root->right, 1), 
            solve(root->left, 0) + solve(root->right, 0));
    }
    int rob(TreeNode* root) {
        mp.clear();
        return max(solve(root, 0), solve(root, 1));
    }
};
