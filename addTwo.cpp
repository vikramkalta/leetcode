#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {
    string str = getString(l1);
    string revStr = getReverseString(str);
    string str1 = getString(l2);
    string revStr1 = getReverseString(str1);

    int sum = getSum(revStr, revStr1);
    string sumStr = to_string(sum);
    string revSumStr = getReverseString(sumStr);
    int *arr = getIntArr(revSumStr);

    ListNode *resultList = createList(arr, to_string(sum).length());
    return resultList;
  }

private:
  int getLen(ListNode *l)
  {
    int i = 0;
    while (l && l->val)
    {
      l = l->next;
      i++;
    }
    return i;
  }

private:
  string getString(ListNode *l)
  {
    string str;
    while (l && l->val)
    {
      str.push_back(l->val + '0');
      l = l->next;
    }
    return str;
  }

private:
  string getReverseString(string s)
  {
    int len = s.length();
    string revStr;

    for (int i = len - 1; i >= 0; i--)
      revStr.push_back(s[i]);

    return revStr;
  }

private:
  int getSum(string s1, string s2)
  {
    int num1 = stoi(s1);
    int num2 = stoi(s2);
    return num1 + num2;
  }

private:
  int *getIntArr(string s)
  {
    int len = s.length();
    int *arr = (int *)malloc(sizeof(int) * len);

    for (int i = 0; i < len; i++)
      arr[i] = (int)s[i] - 48;

    return arr;
  }

public:
  ListNode *createList(int *arr, int len)
  {

    ListNode *l = new ListNode();

    ListNode *previous = new ListNode();

    for (int i = 0; i < len; i++)
    {
      if (l != NULL)
      {

        ListNode *curr = new ListNode();
        curr->val = arr[i];
        curr->next = NULL;

        // If first node
        if (!l->val)
        {
          l = curr;
          previous = l;
        }
        else
        {
          previous->next = curr;
          previous = curr;
        }
      }
    }

    return l;
  }
};

void displayList(ListNode *l)
{
  while (l && l->val)
  {
    cout << "val: " << l->val << endl;
    l = l->next;
  }
}

int main()
{
  int arr1[] = {2, 4, 3};
  int len1 = sizeof(arr1) / sizeof(arr1[0]);

  Solution sol;
  ListNode *l1 = sol.createList(arr1, len1);

  int arr2[] = {5, 6, 4};
  int len2 = sizeof(arr2) / sizeof(arr2[0]);

  ListNode *l2 = sol.createList(arr2, len2);

  ListNode *result = sol.addTwoNumbers(l1, l2);

  return 0;
}

// private:
//   char *_getStr(ListNode *l, int length)
//   {
//     char *str;
//     while (l && l->val)
//     {
//       char tempStr[1];
//       tempStr[0] = (char)l->val;
//       if (str[0] == '\0')
//         strcpy(str, tempStr);
//       else
//         strcat(str, tempStr);
//       l = l->next;
//     }
//     return str;
//   }