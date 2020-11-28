#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class Solution
{
public:
  string longestPalindrome(string s)
  {
    vector<string> strVec;

    for (int i = 0; i < s.length(); i++)
    {
      string str;
      for (int j = i; j < s.length(); j++)
      {
        str.push_back(s[j]);
        // Checks if string is palindrome
        if (checkIfPalindrome(str))
          // Keeps all palindrome strings
          strVec.push_back(str);
      }
    }

    string longestStr;
    for (auto i = strVec.begin(); i != strVec.end(); ++i)
    {
      string currStr = *i;
      if (!longestStr.length())
        longestStr = currStr;
      if (longestStr.length() < currStr.length())
        longestStr = *i;
    }
    return longestStr;
  }

private:
  bool checkIfPalindrome(string s)
  {
    string reverseStr;
    int len = s.length();

    for (int i = len - 1; i >= 0; i--)
      reverseStr.push_back(s[i]);
    // cout << (reverseStr == s) << ": val";
    bool isPalindrome = reverseStr == s;
    cout << "isPalindrome::" << isPalindrome;
    return isPalindrome;
  }
};

int main()
{
  string s = "abcdczy";
  string s = "babad";
  Solution sol;
  sol.longestPalindrome(s);
  return 0;
}