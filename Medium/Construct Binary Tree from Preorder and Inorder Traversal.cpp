
// Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 

// Example 1:


// Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
// Output: [3,9,20,null,null,15,7]
// Example 2:

// Input: preorder = [-1], inorder = [-1]
// Output: [-1]
 

// Constraints:

// 1 <= preorder.length <= 3000
// inorder.length == preorder.length
// -3000 <= preorder[i], inorder[i] <= 3000
// preorder and inorder consist of unique values.
// Each value of inorder also appears in preorder.
// preorder is guaranteed to be the preorder traversal of the tree.
// inorder is guaranteed to be the inorder traversal of the tree.
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
 
   // TreeNode* root;
public:

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        unordered_map<int, int> inorder_index_map; 

        for(int i = 0; i<inorder.size(); i++){
            inorder_index_map[inorder[i]] = i;
        }

        int n = preorder.size();
        int m = inorder.size();

        TreeNode* root = build(preorder, 0, n-1, inorder, 0 , m-1, inorder_index_map);

        return root;

        
    
        
    }

    TreeNode* build(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& mp){
        if(preStart> preEnd|| inStart>inEnd)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[preStart]);

        int inRoot = mp[root->val];
        int numLeft = inRoot - inStart;

        root->left = build(preorder, preStart+1, preStart + numLeft, inorder, inStart, inRoot-1,  mp);
        root->right = build(preorder, preStart+numLeft+1, preEnd, inorder, inRoot+1, inEnd, mp);
        return root; 
    }
};