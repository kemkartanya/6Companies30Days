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
    void inorder(TreeNode* root, vector<int>& list) {
        if(root == NULL) return;

        inorder(root->left, list);
        list.push_back(root->val);
        inorder(root->right, list);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> list, list1, list2;
        inorder(root1, list1);
        inorder(root2, list2);

        int i = 0, j = 0;
        int n = list1.size(), m = list2.size();
        while(i < n && j < m) {
            if(list1[i] <= list2[j]) list.push_back(list1[i++]);
            else list.push_back(list2[j++]);
        }
        while(i < n) {
            list.push_back(list1[i++]);
        }
        while(j < m) {
            list.push_back(list2[j++]);
        }
        return list;
    }
};
