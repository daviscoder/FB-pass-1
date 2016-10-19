// O(n), O(1).
// http://www.geeksforgeeks.org/convert-a-binary-tree-to-a-circular-doubly-link-list/

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
private:
    TreeNode * prev;
public:
    void inOrder (TreeNode * root) {
        if (root == NULL) {
            return;
        }
        inOrder (root->left);
        prev->right = root;
        root->left = prev;
        prev = root;
        inOrder (root->right);
    }
    
    TreeNode * bTreeToCList (TreeNode * root) {
        if (root == NULL) {
            return NULL;
        }
        TreeNode * fakeHead = new TreeNode (-1);
        prev = fakeHead;
        inOrder (root);
        fakeHead->right->left = prev;
        prev->right = fakeHead->right;
        prev = NULL;
        return fakeHead->right;
    }
};

void displayCList (TreeNode * head) {
    TreeNode * p = head;
    do {
        cout << p->val << " ";
        p = p->right;
    } while (head != p);
    cout << "\n";
    
    do {
        cout << p->val << " ";
        p = p->left;
    } while (head != p);
    cout << "\n";
}

int main () {
    TreeNode * root = new TreeNode (10);
    root->left = new TreeNode (12);
    root->right = new TreeNode (15);
    root->left->left = new TreeNode (25);
    root->left->right = new TreeNode (30);
    root->right->left = new TreeNode (36);

    Solution s;
    TreeNode * head = s.bTreeToCList(root);
    displayCList (head);
    return 0;
}
