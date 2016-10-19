// O (n), O (height of tree)

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue <pair<int, TreeNode*> > q;
        vector<vector<int>> result;
        if (root == NULL){
            return result;
        }
        q.push ({0, root});
        while (q.empty() == false) {
            int currentLevel = q.front().first;
            TreeNode * currentNode = q.front().second;
            q.pop();
            if (result.size() <= currentLevel) {
                result.push_back (vector<int> ());
            }
            result[currentLevel].push_back (currentNode->val);
            if (currentNode->left) {
                q.push ({currentLevel + 1, currentNode->left});
            }
            if (currentNode->right) {
                q.push ({currentLevel + 1, currentNode->right});
            }
        }
        return result;
    }
};
