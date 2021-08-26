/*
    leetcode id: 11
*/
class Solution {
 public:
  int maxArea(vector<int>& height) {
    if (height.size() <= 1) return 0;
    int result;
    myMaxAreaOPT(height, result);
    return result;
  }
 private:
  void myMaxAreaOPT(vector<int> &arr, int &ans) {
    int i(0), j(arr.size() - 1);
    ans = 0;

    while (i < j) {
      ans = arr[i] < arr[j] ?
          max(ans, (j - i) * arr[i++]) :
          max(ans, (j - i) * arr[j--]);
    }
    return ;
  }
  void myMaxAreaNaive(vector<int> &arr, int &ans) {
    ans = 0;
    for (int i = 0; i < arr.size(); ++i) {
      for (int j = i + 1; j < arr.size(); ++j) {
        ans = max(ans, (j - i) * min(arr[i], arr[j]));
      }
    }
    return ;
  }
};