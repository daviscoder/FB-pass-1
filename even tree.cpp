// DFS, only cut the subtrees with even number of nodes. O(n)

#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
using namespace std;

struct TreeNode {
    int val;
    vector<TreeNode *> children;
    TreeNode (int x) : val(x) {};
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode (int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int helper (TreeNode * root, vector<TreeNode *>& result) {
        if (root == NULL) {
            return 0;
        }
        int count = 1;
        for (int i = root->children.size() - 1; i >= 0; i--) {
            int subTreeSize = helper (root->children[i], result);
            count += subTreeSize;
            if (subTreeSize % 2 == 0) {
                result.push_back(root->children[i]);
                root->children.erase (root->children.begin() + i);
            }
        }
        return count;
    }
    vector<TreeNode *> evenTree (TreeNode * root) {
        vector<TreeNode *> result;
        int totalNodes = helper (root, result);
        if (totalNodes % 2) {
            return vector<TreeNode *> ();
        }
        result.push_back (root);
        return result;
    }
};

int main () {
    TreeNode * root = new TreeNode(1);
    root->children.push_back(new TreeNode (3));
    root->children.push_back(new TreeNode (6));
    root->children.push_back(new TreeNode (2));
    root->children[0]->children.push_back(new TreeNode(4));
    root->children[1]->children.push_back(new TreeNode(8));
    root->children[2]->children.push_back(new TreeNode(7));
    root->children[2]->children.push_back(new TreeNode(5));
    root->children[1]->children[0]->children.push_back(new TreeNode(9));
    root->children[1]->children[0]->children.push_back(new TreeNode(10));

    Solution s;
    vector<TreeNode *> result = s.evenTree (root);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i]->val << "\t";
    }
    cout << endl;
    return 0;
}
