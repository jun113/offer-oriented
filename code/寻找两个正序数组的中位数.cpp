// leetcode id: 4
class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() == 0 && nums2.size() == 0) return 0;
    if (nums2.size() == 0) {
      return nums1.size() % 2 ? nums1[nums1.size()/2] : (nums1[nums1.size()/2 - 1] + nums1[nums1.size()/2]) / 2.0;
    }
    if (nums1.size() == 0) {
      return nums2.size() % 2 ? nums2[nums2.size()/2] : (nums2[nums2.size()/2 - 1] + nums2[nums2.size()/2]) / 2.0;
    }
    double result;
    myFindMedianSortedArraysDivide(nums1, nums2, result);
    return result;
  }
 private:
  void myFindMedianSortedArraysDivide(vector<int> &arr1, vector<int> &arr2, double &ans) {
    int m = arr1.size();
    int n = arr2.size();
    int left = (m + n + 1) / 2;
    int right = (m + n + 2) / 2;
    ans = (FindKth(arr1, 0, arr2, 0, left) + FindKth(arr1, 0, arr2, 0, right)) / 2.0;
    return ;
  }
  int FindKth(vector<int> &arr1, int i, vector<int> &arr2, int j, int k) {
    if (i >= arr1.size()) return arr2[j + k - 1];
    if (j >= arr2.size()) return arr1[i + k - 1];

    if (k == 1) return min(arr1[i], arr2[j]);

    int midVal1 = (i + k/2 - 1) < arr1.size() ? arr1[i + k/2 - 1] : INT_MAX;
    int midVal2 = (j + k/2 - 1) < arr2.size() ? arr2[j + k/2 - 1] : INT_MAX;

    if (midVal1 < midVal2) {
      return FindKth(arr1, i + k/2, arr2, j, k - k/2);
    } else {
      return FindKth(arr1, i, arr2, j + k/2, k - k/2);
    }
  }
  void myFindMedianSortedArrays(vector<int> &arr1, vector<int> &arr2, double &ans) {
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