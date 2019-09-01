/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void flatten(struct TreeNode* root){
    if(root==NULL)return;
    struct TreeNode* preorder[3001] = {0};
    int cnt = 0;//cnt for the valid size of array preorder
    struct TreeNode* stack[1001] = {0};
    int top = -1;//the top pointer of the stack
    stack[++top] = root;
    while(top>=0){
        struct TreeNode *node = stack[top--];
        if(node){
            preorder[cnt++] = node;
            stack[++top] = node->right;
            while(node->left){
                node = node->left;
                preorder[cnt++] = node;
                if(node->right)stack[++top] = node->right;
            }
        }
    }
    // for(int i = 0;i<cnt;i++)if(preorder[i])printf("%d ",preorder[i]->val);else puts("null ");
    cnt--;
    for(int i = 0;i<cnt;i++){
        preorder[i]->right = preorder[i+1];
        preorder[i]->left = NULL;
    }
    preorder[cnt]->left = NULL;
    preorder[cnt]->right = NULL;
}

