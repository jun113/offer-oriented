/*
  nowcoder id: 19
*/
class Solution {
 public:
    /**
     * max sum of the subarray
     * @param arr int vector the array
     * @return int
     */
  int maxsumofSubarray(vector<int>& arr) {
        // write code here
    if (arr.size() <= 1) return arr[0];
    int result;
    mymaxsumofSubarrayOPT(arr, result);
    return result;
  }
 private:
  void mymaxsumofSubarrayNaive(vector<int> &arr, int &ans) {
    ans = 0;
    for (int i = 0; i < arr.size(); ++i) {
      int temp = 0;
      for (int j = 0; j < arr.size()-i; ++j) {
        temp += arr[i+j];
        ans = max(temp, ans);
      }
    }
    return ;
  }
  void mymaxsumofSubarrayDP(vector<int> &arr, int &ans) {
    vector<int> opt(arr.size(), 0);
    ans = arr[0];
    opt[0] = arr[0];
    for (int i = 1; i < arr.size(); ++i) {
      opt[i] = max(arr[i], opt[i-1] + arr[i]);
      ans = max(opt[i], ans);
    }
    return ;
  }
  void mymaxsumofSubarrayOPT(vector<int> &arr, int &ans) {
    int opt = arr[0];
    ans = arr[0];
    for (int i = 1; i < arr.size(); ++i) {
      opt = max(opt + arr[i], arr[i]);
      ans = max(opt, ans);
    }
    return ;
  }
};