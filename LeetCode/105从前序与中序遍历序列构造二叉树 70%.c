/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//assumes that there is no repeated num in the tree

void createTree(struct TreeNode *root, int *preorder, int *inorder, int inSize){
    root->val = (*preorder);
    int inIndex = 0;
    for(;inIndex<inSize;inIndex++){
        if(inorder[inIndex]==root->val){
            break;
        }
    }
    if(inIndex){
        root->left = malloc(sizeof(struct TreeNode));
        createTree(root->left,preorder+1,inorder,inIndex);
    }else {root->left = NULL;}
    if(inIndex+1<inSize){
        root->right = malloc(sizeof(struct TreeNode));
        createTree(root->right,preorder+inIndex+1,inorder+inIndex+1,inSize-inIndex-1);
    }else {root->right = NULL;}
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    struct TreeNode* root = NULL;
    if(preorderSize){
        root = malloc(sizeof(struct TreeNode));
        createTree(root,preorder,inorder,inorderSize);
    }
    return root;
}

