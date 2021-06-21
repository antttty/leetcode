#include <stdlib.h>
#include <string.h>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
 
void dfs(struct TreeNode* root, int* returnSize, int *ret)
 {
     if (root == NULL)
        return ;
    if (root->left != NULL)
        dfs(root->left, returnSize, ret);
        ret[(*returnSize)++] = root->val;
    if (root->right != NULL)
        dfs(root->right, returnSize, ret);
 }

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int *ret = (int *)malloc(100 * sizeof(int));
    bzero(ret, 100*sizeof(int));
    *returnSize = 0;
    dfs(root, returnSize, ret);
    return ret;
}

int main()
{
    struct TreeNode node1 = {1, NULL, NULL};
    struct TreeNode node2 = {2, NULL, NULL};
    struct TreeNode node3 = {3, NULL, NULL};

    node1.right = &node2;
    node2.left = &node3;

    int tmp = 0;
    int *ptr = &tmp;

    int *pret = inorderTraversal(&node1, ptr);

    int ret = 0;
    int ret2 = 0;
    
    return 0;
}