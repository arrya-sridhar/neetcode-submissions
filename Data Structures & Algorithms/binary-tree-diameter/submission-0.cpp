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

    int depth(TreeNode* node){
        if(node==nullptr) return 0;
        return 1 + max(depth(node->left),depth(node->right));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;
        int ans = depth(root->left) + depth(root->right);
        return max(ans,max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)));
    }
};
