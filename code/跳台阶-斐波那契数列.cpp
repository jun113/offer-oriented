/*
  nowcoder id: 65, 68
*/
class Solution {
 public:
  int jumpFloor(int number) {
    int result;
    result = myJumpFloorRecursion(number);
    return result;
  }
 private:
  int myJumpFloorOpt(int n) {
    if (n <= 2) return n;
    else {
      int x = 1;
      int y = 2;
      int z = 0;
      for (int i = 3; i <= n; ++i){
        z = x + y;
        x = y;
        y = z;
      }
      return z;
    }
  }
  int myJumpFloorRecursion(int n) {
    if (n <= 2) return n;
    else {
      return myJumpFloorRecursion(n-1) + myJumpFloorRecursion(n-2);
    }
  }
};