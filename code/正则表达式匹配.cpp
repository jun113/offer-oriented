/*
  leetcode id: 10
  '.': 匹配任意单个字符
  '*': 匹配任意个前一个字符
*/
class Solution {
 public:
  bool isMatch(string s, string p) {
    bool result;
    myIsMatch(s, p, result);
    return result;

  }
 private:
  void myIsMatch(string s, string p, bool &ans) {
    ans = match(s.data(), p.data());
  }
  bool match(char *s, char *p) {
    if (!*p) return !*s;
    if (*(p + 1) != '*') {
      return *s == *p || (*p == '.' && *s != '\0') ? match(s + 1, p + 1) : false;
    } else {
      //                                            匹配0个'*'前字符     匹配'*'前字符        不匹配
      return *s == *p || (*p == '.' && *s != '\0') ? match(s, p + 2) || match(s + 1, p) : match(s, p + 2);
    }
  }
};