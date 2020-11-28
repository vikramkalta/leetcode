#include <iostream>

using namespace std;

void printArray(int arr[], int size)
{
  for (int i = 0; i < size; i++)
    printf("%d\n", arr[i]);
}

void merge(int arr[], int l, int m, int r)
{
  // int ml = m - l;
  // cout << "m-l" << ml;
  // int l1 = l + 1;
  // cout << "l+1" << l1;
  // int ml1 = m-l+1;
  // cout << "ml1" << ml1;
  int n1 = m - l + 1;
  int n2 = r - m;

  // Initialise L and R arrays
  int L[n1];
  int R[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[l + i];

  for (int j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j];

  int i = 0, j = 0, k = l;
  // Merge arrays
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

  // Copy rest of the elements
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

void mergeSort(int arr[], int l, int r)
{
  if (l < r)
  {
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    printArray(arr, 6);
    merge(arr, l, m, r);
  }
}
