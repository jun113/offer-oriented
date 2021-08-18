class Solution {
 public:
  vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    if (k == 0) return vector<int> ();
    if (k >= input.size()) return input;
    
    // »ùÓÚ¿ìÅÅ
    QuickSort(input, 0, input.size()-1, k);
    return vector<int>({input.begin(), input.begin() + k});
  }
 private:
  void QuickSort(vector<int> &arr, const int low, const int high, const int k) {
    if (low > high) return ;
    int privot = Partition(arr, low, high);
    if (privot == k-1) return;
    else if (privot > k) QuickSort(arr, low, privot-1, k);
    else QuickSort(arr, privot+1, high, k);
  }
  int Partition(vector<int> &arr, int low, int high) {
    int temp = arr[low];
    while (low < high) {
      while (low < high && temp <= arr[high]) --high;
      arr[low] = arr[high];
      while (low < high && arr[low] <= temp) ++low;
      arr[high] = arr[low];
    }
    arr[low] = temp;
    return low;
  }
};