// leetcode id: 4
class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

    double result;
    myFindMedianSortedArraysNaive(nums1, nums2, result);
    return result;

  }
 private:
  void myFindMedianSortedArraysNaive(vector<int> &arr1, vector<int> &arr2, double &ans) {
    int i(0), j(0);
    int x, y;
    int length = (arr1.size() + arr2.size()) / 2;
    for (int k = 0; k <= length; ++k) {
      x = y;
      if (i != arr1.size() && j != arr2.size()) {

        if (arr1[i] < arr2[j]) {
          y = arr1[i++];
        } else {
          y = arr2[j++];
        }
      } else if (i == arr1.size()) {
        y = arr2[j++];
      } else {
        y = arr1[i++];
      }
    }
    ans = (arr1.size() + arr2.size()) % 2 ? (double)y : (x + y) / 2.0;
  }
};