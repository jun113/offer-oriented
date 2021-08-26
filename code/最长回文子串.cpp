/*
    leetcode id: 5
*/
class Solution {
 public:
  string longestPalindrome(string s) {
    if (s.size() <= 1) return s;

    string result;

    myLongestPalindromeDP(s, result);

    return result;
  }
  void myLongestPalindromeDP(string s, string &ans) {
    /*
        dp(i,i)   <- true;
        dp(i,i+1) <- s(s[i] == s[i+1]);
        dp(i,j)   <- dp(i+1,j-1) .and. (s[i] == s[j])
    */
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));

    for (int l = 0; l < s.size(); ++l) {
      for (int i = 0; i + l < s.size(); ++i) {
        int j = i + l;
        if (l == 0) dp[i][j] = true;
        else if (l == 1) dp[i][j] = (s[i] == s[j]);
        else dp[i][j] = dp[i+1][j-1] && (s[i] == s[j]);
        if(dp[i][j] && l + 1 > ans.size()) ans = s.substr(i, l+1);
      }
    }
    return ;
 }
};