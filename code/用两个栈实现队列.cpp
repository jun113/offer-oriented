// nowcoder id: 76
// offer    id: 09
class Solution
{
 public:
  void push(int node) {
    stack1.push(node);
    return ;
  }

  int pop() {
    int out = 0;
    if (stack1.empty() && stack2.empty()) return out;
    if (stack2.empty()) {
      while (!stack1.empty()) {
        stack2.push(stack1.top());
        stack1.pop();
      }
    }
    out = stack2.top();
    stack2.pop();
    return out;
  }
 private:
  stack<int> stack1;
  stack<int> stack2;
};