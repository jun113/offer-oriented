/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
 public:
    /**
     * 
     * @param root TreeNode类 the root of binary tree
     * @return int整型vector<vector<>>
     */
  //分别按照二叉树先序，中序和后序打印所有的节点。
  vector<vector<int> > threeOrders(TreeNode* root) {
    if (!root) return vector<vector<int>> ();
    vector<vector<int> > result(3);
    preorderTraversalNotRecursion(root,  result[0]);
    midorderTraversalNotRecursion(root,  result[1]);
    postorderTraversalNotRecursion(root, result[2]);
    return result;
  }
 private:
  // 非递归前序遍历
  void preorderTraversalNotRecursion(TreeNode *root, vector<int> &result) {
    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty()) {
      TreeNode *node = st.top();
      st.pop();
      if (node) {
        if (node->right) st.push(node->right);
        if (node->left)  st.push(node->left);
        st.push(node);
        st.push(nullptr);
      } else {
        node = st.top();
        st.pop();
        result.push_back(node->val);
      }
    }
    return ;
  }
  // 非递归中序遍历
  void midorderTraversalNotRecursion(TreeNode *root, vector<int> &result) {
    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty()) {
      TreeNode *node = st.top();
      st.pop();
      if (node) {
        if (node->right) st.push(node->right);
        st.push(node);
        st.push(nullptr);
        if (node->left) st.push(node->left);
      } else {
        node = st.top();
        st.pop();
        result.push_back(node->val);
      }
    }
    return ;
  }
  // 非递归后序遍历
  void postorderTraversalNotRecursion(TreeNode *root, vector<int> &result) {
    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty()) {
      TreeNode *node = st.top();
      st.pop();
      if (node) {
        st.push(node);
        st.push(nullptr);
        if (node->right) st.push(node->right);
        if (node->left) st.push(node->left);
      } else {
        node = st.top();
        st.pop();
        result.push_back(node->val);
      }
    }
    return ;
  }
};