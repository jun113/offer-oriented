class Solution {
 public:
    /**
     *
     * @param numbers int����vector
     * @param target int����
     * @return int����vector
     */
  vector<int> twoSum(vector<int>& numbers, int target) {
    // ţ�͵� 61 ��, С���1��ʼ��
    // Leetcode �� 1 ��
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