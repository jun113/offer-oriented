dp[n] = 2dp[n-1];

public int JumpFloorII(int target) {
  return (int) Math.pow(2, target-1);
}
