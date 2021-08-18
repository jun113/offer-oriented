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
     * @param root TreeNode类 
     * @return int整型vector<vector<>>
     */
  vector<vector<int> > levelOrder(TreeNode* root) {
    if (!root) return vector<vector<int>> ();
    vector<vector<int>> ans;
    
    levelOrderDeque(root, ans);
    return ans;
  }
 private:
  // 基于队列
  void levelOrderDeque(TreeNode *root, vector<vector<int>> &ans) {
    deque<TreeNode*> queue;
    queue.push_back(root);
    while (!queue.empty()) {
      auto count = queue.size();
      vector<int> level;
      while (count--) {
        TreeNode *node = queue.front();
        queue.pop_front();
        level.push_back(node->val);
        if (node->left) queue.push_back(node->left);
        if (node->right) queue.push_back(node->right);
      }
      ans.push_back(level);
    }
    return ;
  }
};