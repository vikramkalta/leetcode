#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  string convert(string s, int numRows)
  {
    int len = s.length();

    int i = 0;
    int rounds = 0;
    string resultStr;
    resultStr.resize(len);

    // int verticalLength = 0;
    int columnCount = 0;
    // total columns to be created
    int totalColumns = len / numRows + 1;
    // when iterating calculate index and push the element in right place
    do
    {
      if (numRows % len == 0)
      {
        // int calcIndex = 
      }
      // Calculate the index
      if (columnCount == 0)
      {

        resultStr.push_back(s[i]);
      }
      else
      {
      }

      // if initial column
      // int indexToPushCurrentChar = numRows - verticalLength - 1;

      // if (verticalLength == 0)
      // {
      //   int adjustedIndex = i * numRows;
      //   auto itPos = resultStr.begin() + adjustedIndex;
      //   resultStr.insert(itPos, s[i]);
      // }
      // else
      // {
      //   auto itPos = resultStr.begin() + i;
      //   resultStr.insert(itPos, s[i]);
      // }
      // int adjustedNumRowsVal = numRows - 1;
      // if (i % numRows == 0)
      //   resultStr.push_back(s[(adjustedNumRowsVal - i) * 2]);
      // else
      // {
      //   resultStr.push_back(s[(adjustedNumRowsVal - i) * 2]);
      // }

      // if first row
      // int indexToPush = i * (numRows + numRows - 2); // n+n-2 is index for 1st row
      // // if second row
      // int secondRowIndex = i * (numRows + numRows - 2) - 1;
      // resultStr.push_back(s[indexToPush]);

      i = i % len + 1;
      // i = i % len + 1;

      if (i >= 14)
      {
        rounds++;
        i = 0 + rounds;
      }

      cout << "i::" << i << endl;
      cout << "s[i]::" << s[i] << endl;
    } while (true);
  }
};

int main()
{
  string s = "PAYPALISHIRING";
  // string s = "AB";
  // string s = "hiklorxwaciwybmsfgwitrcytzmzlpvszhfnadlcfuadxmycvumqmrphqbgbsevsnbfqgtulnvrmhpoejcvxtmfjnnmgriahlfxrarenovzwkpcwsxtljaxzojhhthogonzpheevzetkvygpvbdhcaisjpbfwslmflbopgmqmfcjdkzbmckqeskpjluhditltvzkdlaptdyynzbbdlthfdzopvvudpfymhipslenqemfenhjbcrggsxxnsrtjxrveckypqofxckbrtkswdbexyblqsearxxxbiwqakvxoiafdnybszfqxibpdhrugpsizqyzcwzqgzvjovnhuuxtdalgjccpruzqkysmwrecsalhvaqsvnlynygybinufpnpnfejyinskybgzrywelutkctnkjhryujnbpwbxluklvqkpqivdcrpgkcttmkrgtekiclinfszdklscuphygzhrdampmeygkiqptacbudggraknpslwrupuubmhhkpsuhhnklqepwniwxvmpikidzdzargibxcvhjkrudvlzitwiqkxzugctlbtekdfjfcqqohnrfytpupxkzvltdnoqrjubnbkufdltkynpygfsxcfyzqreghuxqoadrmywpjscjfrhnyakdhiczbjfideaugelvekkpcmyjgfwghijqsoqtxxdacdwkjifpusgweefmmdtvlcmdqeypbdqfimqswvjqnqouwvgkybijguowyombrehasxurufjkvaeuvmguoofukuskkgmcmvehsyyodjybjcxfrdbfugbecvpnedrqyvxstxgyjf";
  int rows = 467;
  Solution sol;
  string resultStr = sol.convert(s, 3);
  return 0;
}

// NUMROWS 4
// P    I     N
// A  L S   I G
// Y A  H R
// P    I

// PINALSIGYAHRPI

// NUMROWS 5
// P       H
// A     S I
// Y   I   R
// P L     I G
// A       N

// PHASIYIRPLIGAN

// paypalishiring

// p(0)      a(4)      h(8)       n(12)
// a(1) p(3) l(5) s(7) i(9) i(11) g(13)
// y(2)      i(6)      r(10)

// P(0)        I(6)         N(12)
// A(1)   L(5) S(7)   I(11) G(13)
// Y(2) A(4)   H(8) R(10)
// P(3)        I(9)
// P  A    Y    P

// P(0)          H(8)
// A(1)     S(7) I(9)
// Y(2)   I(6)   R(10)
// P(3) L(5)     I(11) G(13)
// A(4)          N(12)

// P(0)                  R(10)
// A(1)             I(9) I(11)
// Y(2)         H(8)     N(12)
// P(3)     S(7)         G(13)
// A(4) I(6)
// L(5)

// class Solution
// {
// public:
//   string convert(string s, int numRows)
//   {
//     int len = s.length();

//     string resultString;
//     resultString.reserve(len);

//     vector<char> columnStrVec;
//     columnStrVec.reserve(numRows);

//     vector<vector<char>> strVec;
//     int strVecReserve = len / numRows + 1;
//     strVec.reserve(strVecReserve);

//     int verticalLength = 0;

//     for (int i = 1; i <= len; i++)
//     {
//       // If initial column
//       int indexToPushCurrentChar = numRows - verticalLength - 1;
//       // index to push
//       int indexToPush = i - 1;

//       if (indexToPushCurrentChar <= 0)
//         verticalLength = 0;

//       if (verticalLength == 0)
//         columnStrVec.push_back(s[indexToPush]);
//       else
//       {
//         for (int j = 0; j < numRows; j++)
//         {
//           if (indexToPushCurrentChar == j)
//             columnStrVec.push_back(s[indexToPush]);
//           else
//             columnStrVec.push_back('\0');
//         }
//       }

//       if (columnStrVec.size() == numRows || i == len)
//       {
//         verticalLength++;
//         // Push the vector char in vector of vector of char
//         strVec.push_back(columnStrVec);

//         // Empty the column wise vector
//         while (!columnStrVec.empty())
//           columnStrVec.pop_back();
//       }
//     }

//     for (int j = 0; j < numRows; j++)
//     {
//       for (auto i = strVec.begin(); i != strVec.end(); i++)
//       {
//         vector<char> charVec;
//         charVec.reserve(numRows);
//         charVec = *i;
//         int charVecSize = charVec.size();

//         if (charVec[j] != '\000' && charVecSize > j)
//           resultString.push_back(charVec[j]);
//       }
//     }
//     return resultString;
//   }
// };