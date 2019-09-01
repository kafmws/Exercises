/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* recoverFromPreorder(char * S){
    struct TreeNode* nodeInDepths[1001];//nodeInDepths[i] recent node in floor i
    memset(nodeInDepths,0,sizeof(struct TreeNode*)*1000);
    int depthCnt = 0;//counter for former arrays;
    int cnt = 0;//cnt for '-'
    while(*S){
        if((*S)=='-'){cnt++;S++;}
        else{
            struct TreeNode* node = malloc(sizeof(struct TreeNode));
            node->val = 0;
            while((*S)>='0'&&(*S)<='9'){
                node->val *= 10;
                node->val += (*S)-48;
                S++;
            }
            node->left = node->right = NULL;
            nodeInDepths[cnt] = node;
            if(cnt){
                struct TreeNode *parent = nodeInDepths[cnt-1];
                if(parent){
                    if(parent->left==NULL)parent->left = node;
                    else parent->right = node;
                }
            }
            // printf("%d f:%d\n",node->val,cnt);
            cnt = 0;
        }
    }
    return nodeInDepths[0];
}

