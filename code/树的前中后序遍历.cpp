// nowcoder id: 45
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
     * @param root TreeNodeç±? the root of binary tree
     * @return intæ´åvector<vector<>>
     */
  //åå«æç§äºåæ ååºï¼ä¸­åºåååºæå°ææçèç¹ã?
  vector<vector<int> > threeOrders(TreeNode* root) {
    if (!root) return vector<vector<int>> ();
    vector<vector<int> > result(3);
    preorderTraversalNotRecursion(root,  result[0]);
    midorderTraversalNotRecursion(root,  result[1]);
    postorderTraversalNotRecursion(root, result[2]);
    return result;
  }
 private:
  // ééå½ååºéå
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
  // ééå½ä¸­åºéå
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
  // ééå½ååºéå
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