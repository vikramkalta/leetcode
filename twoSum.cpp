#include <vector>
#include <iostream>

using std::vector;
using namespace std;

class Solution
{
public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
    int i = 0, j = 0, foundPair = false;
    int len = nums.size();
    vector<int> result;

    for (i = 0; i < len; i++)
    {
      for (j = 0; j < len; j++)
      {
        if (i != j)
        {
          int sum = nums[i] + nums[j];
          cout << "sum" << sum;
          if (sum == target)
          {
            result.push_back(i);
            result.push_back(j);
            foundPair = true;
            break;
          }
        }
      }
      if (foundPair)
        break;
    }
    return result;
  }
};

int main()
{
  Solution sol;
  int nums[4] = {2, 7, 11, 15};

  vector<int> g1;
  int len = sizeof(nums) / sizeof(nums[0]);

  cout << "length: " << len << endl;

  for (int i = 0; i < len; i++)
    g1.push_back(nums[i]);

  for (auto i = g1.begin(); i != g1.end(); ++i)
    cout << *i << " ";

  sol.twoSum(g1, 9);
}