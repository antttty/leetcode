 #include <stdlib.h>
 #include <string.h>

  struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };

struct TreeNode* help(int* nums, int l, int r){
    if (l > r)
        return NULL;

    int     mid = l + (r - l)/2;
    struct TreeNode* cur = (struct TreeNode*)malloc(1 * sizeof(struct TreeNode));
    bzero(cur, sizeof(struct TreeNode));
    cur->val = nums[mid];
    cur->left = help(nums, l, mid-1);
    cur->right = help(nums, mid+1, r);
    return cur;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    struct TreeNode* ret = help(nums, 0, numsSize-1);
    return ret;
}

int main(){
    int nums[] = {-10, -3, 0, 9, 5};
    struct TreeNode *ret = sortedArrayToBST(nums, 5);

    return 0;

}