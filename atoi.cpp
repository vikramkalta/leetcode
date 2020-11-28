#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

class Solution
{
public:
  int myAtoi(string s)
  {
    string newS;
    bool isNegative = false;

    int len = s.length();

    if (len == 0)
      return 0;

    for (int i = 0; i < len; i++)
    {
      char ch = s[i];

      if (ch == ' ' && newS.empty())
      {
        continue;
      }
      if (ch != '-' && ch != '+' && !isdigit(ch) && newS.empty())
        return 0;

      if ((ch == '-' || ch == '+') && newS.empty())
      {
        isNegative = ch == '-';
        newS.push_back(ch);
        continue;
      }
      if (isdigit(ch))
      {
        newS.push_back(ch);
        continue;
      }
      if (!isdigit(ch) && !newS.empty())
      {
        int convertToInt;
        try
        {
          convertToInt = stoi(newS);
        }
        catch (const out_of_range &e)
        {
          string err = e.what();
          cout << "Error outer catch: " << err << endl;
          if (isNegative)
            return INT32_MIN;
          else
            return INT32_MAX;
        }
        catch (...)
        {
          // cout << "Error catch all: " <<
          return 0;
        }
        return convertToInt;
      }
    }

    int convertToInt;
    try
    {
      convertToInt = stoi(newS);
    }
    catch (const out_of_range &e)
    {
      string err = e.what();
      cout << "Error outer catch: " << err << endl;
      if (isNegative)
        return INT32_MIN;
      else
        return INT32_MAX;
    }
    catch (...)
    {
      // cout << "Error catch all: " <<
      return 0;
    }

    return convertToInt;
  }
};

int main()
{
  Solution sol;
  // string s = "     4194 with words";
  // string s = "42";
  // string s = "   -42";
  // string s = "-91283472332";
  // string s = "+-12";
  // string s = "";
  // string s = "+";
  // string s = "   +0 123";
  // string s = "words and 987";
  string s = "      -11919730356x";
  sol.myAtoi(s);
  return 0;
}