// nowcoder id: 140
class Solution {
 public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即�?
     * 将给定数组排�?
     * @param arr int整型vector 待排序的数组
     * @return int整型vector
     */
  vector<int> MySort(vector<int>& arr) {
    if (arr.size() <= 1) return arr;
    QuickSort(arr, 0, arr.size()-1);
    return arr;
  }
 private:
  //---------------------------------------
  // 快速排�?
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
  //---------------------------------------
  // 归并排序 需要临时数组
  void MergeSort(vector<int> &arr, vector<int> &temp, const int &start, const int &end) {
    if (start >= end) return;
    auto mid = start + ((end - start) >> 2);
    MergeSort(arr, temp, start, mid);
    MergeSort(arr, temp, mid + 1, end);
    Merge(arr, temp, start, mid, end);
    return ;
  }
  void Merge(vector<int> &arr, vector<int> &temp, const int &start, const int &mid, const int &end) {
    int i(start), j(mid + 1);
    int k = start;
    while (i <= mid && j <= end) {
      temp[k++] = arr[i] < arr[j] ? arr[i++] : arr[j++];
    }
    while(i <= mid) temp[k++] = arr[i++];
    while(j <= end) temp[k++] = arr[j++];
    for (k = start; k <= end; ++k) {
      arr[k] = temp[k];
    }
    return ;
  }
  // 堆排序
};