#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class Solution
{
public:
  int lengthOfLongestSubstring(string s)
  {
    vector<string> strVec;

    if (!s.length())
      return 0;

    string resultStr, longestStr;
    // Loop through string and remove the first occurence of repeated char
    for (int i = 0; i < s.length(); i++)
    {
      if (indexOf(resultStr, s[i]))
      {
        // This vector holds all the non repeating substrings
        strVec.push_back(resultStr);
        resultStr = removeFirstOccurenceOfChar(resultStr, s[i]);
      }

      resultStr.push_back(s[i]);
    }

    strVec.push_back(resultStr);
    // if (strVec.empty())
    //   return resultStr.length();

    for (auto i = strVec.begin(); i != strVec.end(); ++i)
    {
      string currStr = *i;
      if (!longestStr.length())
        longestStr = currStr;
      if (longestStr.length() < currStr.length())
        longestStr = *i;
    }
    return longestStr.length();
    // return resultStr.length();
  }

private:
  bool indexOf(string str, char c)
  {
    for (int i = 0; i < str.length(); i++)
      if (str[i] == c)
        return true;

    return false;
  }

private:
  string removeFirstOccurenceOfChar(string str, char c)
  {
    for (int i = 0; i < str.length(); i++)
      if (str[i] == c)
      {
        // remove this character
        str.erase(0, i + 1);
        break;
      }
    return str;
  }
};

int main()
{
  Solution sol;
  // string s = "abcdefalmnopqrst";
  // string s = "abcabcbb";
  string s = "aab";
  // string s = "abcdaefghijklb";
  // string s = "pwwkew";
  // string s = "cdd";
  // string s = "abcdefghh";
  // string s = "dvdf";
  // string s = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
  // string s = " ";
  // string s = "ohomm";
  // string s = "abcdefaxyz";
  sol.lengthOfLongestSubstring(s);
  return 0;
}
