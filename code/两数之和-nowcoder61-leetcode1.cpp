class Solution {
 public:
    /**
     *
     * @param numbers intvector
     * @param target int
     * @return int vector
     */
  vector<int> twoSum(vector<int>& numbers, int target) {
    // nowcoder id: 61
    // Leetcode id: 1
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