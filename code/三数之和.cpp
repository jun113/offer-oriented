/*
    leetcode id: 15
*/
class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    if (nums.size() < 3) return {};
    vector<vector<int>> result;
    myThreeSum(nums, result);

    return result;
  }
 private:
  void myThreeSum(vector<int> &arr, vector<vector<int>> &ans) {
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); ++i) {
      if (arr[i] > 0) return;
      if (i > 0 && arr[i - 1] == arr[i]) continue;
      int left = i + 1;
      int right = arr.size() - 1;
      while (left < right) {
        if (arr[i] + arr[right] < 0 - arr[left]) {
          ++left;
        }
        else if (arr[i] + arr[right] > 0 - arr[left]) {
          --right;
        } else {
          ans.push_back({arr[i], arr[left], arr[right]});
          while (left < right && arr[left] == arr[left + 1])
            ++left;
          ++left;
          while (left < right && arr[right - 1] == arr[right])
            --right;
          --right;
        }
      }
    }
    return ;
  }
};