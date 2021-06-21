    #include <vector>
    #include <stack>
    using namespace std;
    
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (root == nullptr)
            return ret;
        stack<TreeNode*> stk;
        while(root != nullptr || !stk.empty()) /*注意该怎么处理*/
        {
            while(root != nullptr){
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            ret.push_back(root->val);
            stk.pop();
            root = root->right;          
        }
        return ret;
    }

    int main(){    
        TreeNode node3(3);
        TreeNode node2(2, &node3, nullptr);
        TreeNode node1(1, nullptr, &node2);
        TreeNode *pnode = &node1;
        vector<int> ret = inorderTraversal(pnode);
        return 0;
    }