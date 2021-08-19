class Solution {
 public:
  int findKth(vector<int> a, int n, int K) {
    QuickSort(a, 0, n-1, K);
    return a[K-1];
  }
 private:
//--------------------------------------------------------
  // 基于快排，找出第K大数，包括重复元素 不用去重
  void QuickSort(vector<int> &arr, const int low, const int high, const int k) {
    if (low > high) return ;
    int privot = Partition(arr, low, high);
    if (privot == k-1) return ;
    else if (privot >= k) QuickSort(arr, low, privot-1, k);
    else QuickSort(arr, privot+1, high, k);
  }
  int Partition(vector<int> &arr, int low, int high) {
    int temp = arr[low];
    while (low < high) {
      while (low < high && temp >= arr[high]) --high;
      arr[low] = arr[high];
      while (low < high && arr[low] >= temp) ++low;
      arr[high] = arr[low];
    }
    arr[low] = temp;
    return low;
  }
//-----------------------------------------------------
};