class Solution {
 public:
    /**
     *
     * @param numbers int整型vector
     * @param target int整型
     * @return int整型vector
     */
  vector<int> twoSum(vector<int>& numbers, int target) {
    // 牛客第 61 题, 小标从1开始算
    // Leetcode 第 1 题
    if (numbers.size() <= 1) return numbers;
    vector<int> result;
    myTwoSum(numbers, target, result);
    return result;
  }
 private:
  void myTwoSum(vector<int> &numbers, const int target, vector<int> &ans) {
    for (int i = 0; i < numbers.size()-1; ++i) {
      for (int j = i+1; j < numbers.size(); ++j) {
        if (numbers[i] + numbers[j] == target) {
          ans.push_back(++i);
          ans.push_back(++j);
          return ;
        }
      }
    }
    return ;
  }
};