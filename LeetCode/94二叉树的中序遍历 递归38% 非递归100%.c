/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//100%
//正宗中序遍历
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    int *res = malloc(sizeof(int)*100);
    struct TreeNode *stack[100] = {0};
    int top = 0;
    while(top||root){
        if(root){
            while(root->left){
                stack[top++] = root;
                root = root->left;
            }
        }
        else{
            top--;
            root = stack[top];
            
        }
        res[(*returnSize)++] = root->val;
        root = root->right;
    }
    return res;
}


//瞎写
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int *res = malloc(sizeof(int)*1000);
    *returnSize = 0;
    struct TreeNode *stack[100]={0};
    int top = 1;
    int flag = 1;
    while(top||root) {
        while(root){
            if(flag){
                while(root->left){
                    stack[top++] = root;
                    root = root->left;
                }
            }
            res[(*returnSize)++] = root->val;
            flag = 1;
            root = root->right;
        }
        top--;
        flag = 0;
        root = stack[top];
    }
    return res;
}
 
 
//38%
//void re(struct TreeNode* root, int *res, int* cnt){
//    if(root->left)re(root->left,res,cnt);
//    res[(*cnt)++] = root->val;
//    if(root->right)re(root->right,res,cnt);
//}
//
//int* inorderTraversal(struct TreeNode* root, int* returnSize){
//    int *res = malloc(sizeof(int)*100);
//    *returnSize = 0;
//    if(root)re(root,res,returnSize);
//    return res;
//}

