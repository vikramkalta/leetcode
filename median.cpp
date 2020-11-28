#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution
{
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
  {
    // Merge array such that they can be sorted
    int size_of_merged_arr = nums1.size() + nums2.size();
    int *arr = (int *)malloc(sizeof(int) * size_of_merged_arr);
    arr = getMergedArray(nums1, nums2, size_of_merged_arr, arr);
    // Apply merge sort
    mergeSort(arr, 0, size_of_merged_arr - 1);

    printArray(arr, size_of_merged_arr);

    bool isEven = size_of_merged_arr % 2 == 0;

    double median;
    int midIndex = size_of_merged_arr / 2;

    if (isEven)
    {
      double sum = arr[midIndex] + arr[midIndex - 1];
      median = sum / 2;
    }
    else
      median = arr[midIndex];

    return median;
  }

private:
  int *getMergedArray(vector<int> &nums1, vector<int> &nums2, int size, int *arr)
  {
    int a = 0;
    for (auto i = nums1.begin(); i != nums1.end(); ++i)
    {
      arr[a] = *i;
      a++;
    }
    for (auto i = nums2.begin(); i != nums2.end(); ++i)
    {
      arr[a] = *i;
      a++;
    }
    return arr;
  }

public:
  void printArray(int *arr, int size)
  {
    for (int i = 0; i < size; i++)
    {
      if (i == 0)
        cout << endl;
      cout << " " << arr[i];
    }
  }

private:
  void merge(int *arr, int l, int m, int r)
  {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1];
    int R[n2];

    // Split arrays
    for (int i = 0; i < n1; i++)
      L[i] = arr[l + i];

    for (int i = 0; i < n2; i++)
      R[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    // Sort and merge arrays
    while (i < n1 && j < n2)
    {
      if (L[i] <= R[j])
      {
        arr[k] = L[i];
        i++;
      }
      else
      {
        arr[k] = R[j];
        j++;
      }
      k++;
    }
    // Copy rest of the elements in the array
    while (i < n1)
    {
      arr[k] = L[i];
      i++;
      k++;
    }
    while (j < n2)
    {
      arr[k] = R[j];
      j++;
      k++;
    }
  }

private:
  void mergeSort(int *arr, int l, int r)
  {
    if (l < r)
    {
      int m = l + (r - l) / 2;

      mergeSort(arr, l, m);
      mergeSort(arr, m + 1, r);
      // printArray(arr, 6);
      merge(arr, l, m, r);
    }
  }
};

int main()
{
  // vector<int> arr1 = {12, 11, 13, 9};
  // vector<int> arr2 = {5, 4, 3};
  vector<int> arr1 = {1, 2};
  vector<int> arr2 = {3, 4};

  Solution sol;
  double median = sol.findMedianSortedArrays(arr1, arr2);
  cout << "median: " << median;
  return 0;
}
