/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//assumes that there is no repeated num in the tree

void createTree(struct TreeNode *root, int *postorder, int *inorder, int inSize){
    root->val = (*postorder);
    int inIndex = 0;
    for(;inIndex<inSize;inIndex++){
        if(inorder[inIndex]==root->val){
            break;
        }
    }
    if(inIndex){
        root->left = malloc(sizeof(struct TreeNode));
        createTree(root->left,postorder-(inSize - inIndex),inorder,inIndex);
    }else {root->left = NULL;}
    if(inIndex+1<inSize){
        root->right = malloc(sizeof(struct TreeNode));
        createTree(root->right,postorder-1,inorder+inIndex+1,inSize-inIndex-1);
    }else {root->right = NULL;}
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
    struct TreeNode* root = NULL;
    if(inorderSize){
        root = malloc(sizeof(struct TreeNode));
        createTree(root,postorder+postorderSize-1,inorder,inorderSize);
    }
    return root;
}