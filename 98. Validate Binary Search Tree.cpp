// O (number of nodes), O(1)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool helper (TreeNode * root, TreeNode*& previous) {
        if (root == NULL) {
            return true;
        }
        if (helper (root->left, previous) == false) {
            return false;
        }
        else if (previous && previous->val >= root->val) {
            return false;
        }
        previous = root;
        return helper (root->right, previous);
    }
    
    bool isValidBST(TreeNode* root) {
        TreeNode * previous = NULL;
        return helper (root, previous);
    }
};
