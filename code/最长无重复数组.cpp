/*
  nowcoder id: 41
  leetcode id: 3
*/
class Solution {
 public:
    /**
     *
     * @param arr int整型vector the array
     * @return int整型
     */
  int maxLength(vector<int>& arr) {
      // write code here
    if (arr.size() <= 1) return arr.size();
    int result;
    myMaxLengthHash(arr, result);

    return result;
  }
 private:
  void myMaxLengthNaive(vector<int> &arr, int &ans) {
    int start(0), end(0), length(0);
    ans = 0;
  }
  void myMaxLengthHash(vector<int> &arr, int &ans) {
    unordered_map<int, int> hash;
    ans = 0;
    int start(0), end(0), length(0);
    while (end < arr.size()) {
      if (hash.find(arr[end]) != hash.end() && start <= hash[arr[end]]) {
        start = hash[arr[end]] + 1;
        length = end - start;
      }
      hash[arr[end]] = end;
      ++end;
      ++length;
      ans = max(ans, length);
    }
    return ;
  }
};