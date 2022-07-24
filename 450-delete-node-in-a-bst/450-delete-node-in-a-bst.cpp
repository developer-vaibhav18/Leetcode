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
private:
    int key;
    void aux (TreeNode *root, TreeNode *found = NULL) {
        if (root == NULL){
            return;
        } 
         
        
        if (found) {
            if (root->left == NULL) {
                // cout << 1 ;
                // cout << found->val << ' ' << root->val << '\n';
                root->left = found;
                return;
            }
            aux(root->left, found);
            return;
        }
        
        if (root->val < key) {
            if (root->right == NULL) return;
            if (root->right->val == key) {
                TreeNode *temp = root->right->left;
                if (temp) {
                    if (root->right->right == NULL) {
                        root->right = root->right->left;
                        return;
                    }
                    aux(root->right->right, temp);
                }
                root->right = root->right->right;
                return;
            }
            aux(root->right, NULL);
            return;
        }
        
        if (root->left == NULL) return;
        if (root->left->val == key) {
            TreeNode *temp = root->left->left;
            if (temp) {
                if (root->left->right == NULL) {
                    root->left = temp;
                    return;
                }
                aux(root->left->right, temp);
            }
            root->left = root->left->right;
            return;
        }
        aux(root->left, NULL);
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return root;
        this->key = key;
        if (root->val == key) {
            if (root->right == NULL) return root->left;
            if(root->left)
                aux(root->right, root->left);
            return root->right;
        }
        aux(root);
        return root;
    }
};