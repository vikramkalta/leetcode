#include <iostream>
#include <string>
#include <sstream>
#include <typeinfo>

using namespace std;

class Solution
{
public:
  int reverse(int x)
  {
    bool isNegative = false;
    if (x < 0)
    {
      isNegative = true;
      try
      {
        // 2147483648 to 2147483647
        if (x < -2147483647)
          return 0;
        x = x * -1; // convert int to positive
        cout << x << '\n';
      }
      catch (const exception &e)
      {
        cout << "Error :: " << e.what();
        return 0;
      }
    }

    string s;
    stringstream ss;
    ss << x;
    ss >> s;

    string revS;
    for (int i = s.length() - 1; i >= 0; i--)
      revS.push_back(s[i]);

    // object from the class stringstream
    int convertInt;
    try
    {
      convertInt = stoi(revS);
    }
    catch (const out_of_range &oor)
    {
      cout << "out of range error: " << oor.what() << '\n';
      return 0;
    }

    if (isNegative)
      convertInt = convertInt * -1;

    return convertInt;
  }
};

int main()
{
  Solution sol;
  sol.reverse(-2147483648);
  return 0;
}