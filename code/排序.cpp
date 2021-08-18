class Solution {
 public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 将给定数组排序
     * @param arr int整型vector 待排序的数组
     * @return int整型vector
     */
  vector<int> MySort(vector<int>& arr) {
    // write code here
    if (arr.size() <= 1) return arr;
    QuickSort(arr, 0, arr.size()-1);
    return arr;
  }
 private:
  void QuickSort(vector<int> &arr, int low, int high) {
    if (low > high) return ;
    int privot = Partition(arr, low, high);
    QuickSort(arr, low, privot-1);
    QuickSort(arr, privot+1, high);
    return ;
  }
  int Partition(vector<int> &arr, int low, int high) {
    int temp = arr[low];
    while (low < high) {
      while (low < high && temp <= arr[high]) --high;
      swap(arr[low], arr[high]);
      while (low < high && arr[low] <= temp) ++low;
      swap(arr[low], arr[high]);
    }
    return low;
  }
};